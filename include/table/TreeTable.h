#pragma once
#include <table/tablerec.h>
#include <stack>
#include <iostream>


using namespace std;
template <typename TKey, typename TValue>
struct TreeNode {
  TKey key;
  TValue* value;
  TreeNode *left, *right;

  TreeNode(TKey key, TValue* value, TreeNode* l, TreeNode* r ) : key(key), value(value), left(l), right(r) {}
  TreeNode* GetLeft() const { return left; }
  TreeNode* GetRight() const { return right; }
};

template <typename TKey, typename TValue>
class TreeTable : public Table<TKey, TValue> {
 public:
  TreeNode<TKey, TValue>* root;// указатель на корень дерева
  TreeNode<TKey, TValue>** ref;// адрес указателя на вершину-результата в Find
  TreeNode<TKey, TValue>* cur;// указатель на текущую вершину
  int curpos;// номер текущей вершины
  stack<TreeNode<TKey, TValue>*> st;// стек для итератора

 public:
  TreeTable() : Table<TKey, TValue>(),root(nullptr),curpos(0),cur(nullptr), ref(nullptr) {}
  ~TreeTable() {}

  bool IsFull() const override {return false;}

  TValue* Find(TKey k) override {
    TreeNode<TKey, TValue>* node = root;
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
    if (IsFull()) return;

    if (Find(key) != nullptr) {
      TreeNode<TKey, TValue>* node = *ref;
      delete node->value;  // Удаляем старое значение
      node->value = new TValue(d);  // Присваиваем новое значение
      return;
    }

    *ref = new TreeNode<TKey, TValue>(key, new TValue(d), nullptr, nullptr);
    count++;
  }


  void Delete(TKey k) override {
    if (root == nullptr) return;

    if (Find(k) != nullptr) {
      TreeNode<TKey, TValue>* node = *ref;

      if (node->left == nullptr &&
          node->right == nullptr) {  // Удаление листьев
        *ref = nullptr;
      } else if (node->left == nullptr) {  // Удаление узла с одним потомком
        *ref = node->right;
      } else if (node->right == nullptr) {  // Удаление узла с одним потомком
        *ref = node->left;
      } else {  // Удаление узла с двумя потомками
        TreeNode<TKey, TValue>** tmp = &node->left;
        while ((*tmp)->right != nullptr) {
          tmp = &((*tmp)->right);
        }
        node->key = (*tmp)->key;
        delete node->value;  // Удаляем старое значение
        node->value = (*tmp)->value;
        TreeNode<TKey, TValue>* toDelete = *tmp;
        *tmp = (*tmp)->left;
        delete toDelete;
      }

      count--;
    }
  }

  int Reset() override {
    TreeNode<TKey, TValue>* node = cur = root;
    while (!st.empty()) st.pop();
    curpos = 0;
    while (node != nullptr) {
      st.push(node);
      cur = node;
      node = node->GetLeft();
    }
    return IsTabEnded();
  }

  int IsTabEnded() const override {
    return curpos >= count;
    
  }

  int GoNext() override {
      st.pop();
      TreeNode<TKey, TValue>* node = cur->right;
      while (node && !IsTabEnded()) {
        st.push(node);
        node = node->left;
      }
      if (!st.empty()) {
        cur = st.top();
      } else
        cur = nullptr;
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
 
};