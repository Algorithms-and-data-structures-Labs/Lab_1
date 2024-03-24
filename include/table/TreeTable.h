
#pragma once
#include <table/tablerec.h>

#include <iostream>
#include <stack>

using namespace std;
template <typename TKey, typename TValue>
struct TreeNode {
  TKey key;
  TValue* value;
  TreeNode *left, *right;
  int height;

  TreeNode(TKey key, TValue* value, TreeNode* l, TreeNode* r)
      : key(key), value(value), left(l), right(r), height(1) {}
  TreeNode* GetLeft() const { return left; }
  TreeNode* GetRight() const { return right; }
};

template <typename TKey, typename TValue>
class TreeTable : public Table<TKey, TValue> {
 public:
  typename ::TreeNode<TKey, TValue>* root;
  typename ::TreeNode<TKey, TValue>** ref;
  typename ::TreeNode<TKey, TValue>* cur;
  int curpos;
  stack<typename ::TreeNode<TKey, TValue>*> st;

 public:
  TreeTable()
      : Table<TKey, TValue>(),
        root(nullptr),
        curpos(0),
        cur(nullptr),
        ref(nullptr) {}
  ~TreeTable() {}

  bool IsFull() const override { return false; }

  TValue* Find(TKey k) override {
    typename ::TreeNode<TKey, TValue>* node = root;
    ref = &root;
    while (node != nullptr) {
      if (node->key == k) break;
      if (node->key < k)
        ref = &node->right;
      else
        ref = &node->left;
      node = *ref;
    }
    if (node == nullptr) return nullptr;
    TValue* tmp = node->value;
    return tmp;
  }

  void Insert(TKey key, TValue d) override {
    if (Find(key) != nullptr) {
      return;
    }
    root = InsertRecursive(root, key, d);
    this->count++;
  }

  void Delete(TKey k) override {
    if (root == nullptr) return;
    root = DeleteRecursive(root, k);
    this->count--;
  }

  int Reset() override {
    while (!st.empty()) {
      st.pop();
    }
    curpos = 0;
    cur = root;
    return IsTabEnded();
  }

  int IsTabEnded() const override { return curpos >= count; }

  int GoNext() override {
    if (cur == nullptr && !st.empty()) {
      cur = st.top();
      st.pop();
      return 0;
    } else if (cur != nullptr) {
      if (cur->right != nullptr) {
        cur = cur->right;
        while (cur->left != nullptr) {
          st.push(cur);
          cur = cur->left;
        }
        return 0;
      } else {
        cur = nullptr;
        return 0;
      }
    }

    curpos++;
    return IsTabEnded();
  }

  TKey GetKey() const override {
    if (cur != nullptr) {
      return cur->key;
    } else {
      return TKey();
    }
  }

  TValue GetValuePtr() const override {
    if (cur != nullptr) {
      return *(cur->value);
    } else {
      return TValue();
    }
  }
  typename ::TreeNode<TKey, TValue>* RotateLeft(
      typename ::TreeNode<TKey, TValue>* node) {
    typename ::TreeNode<TKey, TValue>* newRoot = node->right;
    node->right = newRoot->left;
    newRoot->left = node;
    return newRoot;
  }

  typename ::TreeNode<TKey, TValue>* RotateRight(
      typename ::TreeNode<TKey, TValue>* node) {
    typename ::TreeNode<TKey, TValue>* newRoot = node->left;
    node->left = newRoot->right;
    newRoot->right = node;
    return newRoot;
  }

  int Height(typename ::TreeNode<TKey, TValue>* node) {
    if (node == nullptr) return 0;
    return max(Height(node->left), Height(node->right));
  }

  int BalanceFactor(typename ::TreeNode<TKey, TValue>* node) {
    if (node == nullptr) return 0;
    return Height(node->right) - Height(node->left);
  }

  typename ::TreeNode<TKey, TValue>* InsertRecursive(
      typename ::TreeNode<TKey, TValue>* node,
                                          TKey key, TValue d) {
    if (node == nullptr) {
      return new typename ::TreeNode<TKey, TValue>(key, new TValue(d), nullptr,
                                                   nullptr);
    }

    if (key < node->key) {
      node->left = InsertRecursive(node->left, key, d);
    } else if (key > node->key) {
      node->right = InsertRecursive(node->right, key, d);
    } else {
      delete node->value;
      node->value = new TValue(d);
      return node;
    }

    int balance = BalanceFactor(node);

    if (balance > 1 && key < node->left->key) {
      return RotateRight(node);
    }

    if (balance < -1 && key > node->right->key) {
      return RotateLeft(node);
    }

    if (balance > 1 && key > node->left->key) {
      node->left = RotateLeft(node->left);
      return RotateRight(node);
    }

    if (balance < -1 && key < node->right->key) {
      node->right = RotateRight(node->right);
      return RotateLeft(node);
    }

    return node;
  }

  typename ::TreeNode<TKey, TValue>* DeleteRecursive(
      typename ::TreeNode<TKey, TValue>* node,
                                          TKey k) {
    if (node == nullptr) return nullptr;

    if (k < node->key) {
      node->left = DeleteRecursive(node->left, k);
    } else if (k > node->key) {
      node->right = DeleteRecursive(node->right, k);
    } else {
      if (node->left == nullptr || node->right == nullptr) {
        typename ::TreeNode<TKey, TValue>* temp =
            (node->left != nullptr) ? node->left : node->right;
        if (temp == nullptr) {
          temp = node;
          node = nullptr;
        } else {
          *node = *temp;
        }
        delete temp;
      } else {
        typename ::TreeNode<TKey, TValue>* temp = FindMin(node->right);
        node->key = temp->key;
        node->value = temp->value;
        node->right = DeleteRecursive(node->right, temp->key);
      }
    }

    if (node == nullptr) return nullptr;

    int balance = BalanceFactor(node);

    if (balance > 1 && BalanceFactor(node->right) >= 0) {
      return RotateLeft(node);
    }

    if (balance < -1 && BalanceFactor(node->left) <= 0) {
      return RotateRight(node);
    }

    if (balance > 1 && BalanceFactor(node->right) < 0) {
      node->right = RotateRight(node->right);
      return RotateLeft(node);
    }

    if (balance < -1 && BalanceFactor(node->left) > 0) {
      node->left = RotateLeft(node->left);
      return RotateRight(node);
    }
    return node;
  }

  typename ::TreeNode<TKey, TValue>* FindMin(
      typename ::TreeNode<TKey, TValue>* node) {
    while (node->left != nullptr) {
      node = node->left;
    }
    return node;
  }
};
