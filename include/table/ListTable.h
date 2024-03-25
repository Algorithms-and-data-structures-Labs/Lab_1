#pragma once
#include <table/tablerec.h>

template <typename TKey, typename TValue>
struct Node {
  TKey key;
  TValue* value;
  Node* next;

  Node(TKey key, TValue* value) : key(key), value(value), next(nullptr) {}
};

template <typename TKey, typename TValue>
class ListTable : public Table<TKey, TValue> {
 private:
  Node<TKey, TValue>* head;
  Node<TKey, TValue>* current;
  Node<TKey, TValue>* prev;

 public:
  ListTable() : head(nullptr) {}

  bool IsFull() const override { return false; }

  TValue* Find(TKey key) override {
    current = head;
    while (current != nullptr) {
      if (current->key == key) {
        return current->value;
      }
      current = current->next;
    }
    return nullptr;
  }

  void Insert(TKey key, TValue value) override {
    TValue* newValue = new TValue(value);
    Node<TKey, TValue>* newNode = new Node<TKey, TValue>(key, newValue);
    newNode->next = head;
    head = newNode;
    this->count++;
    current = head;
  }

  void Delete(TKey key) override {
    current = head;
    prev = nullptr;

    while (current != nullptr && current->key != key) {
      prev = current;
      current = current->next;
    }

    if (current != nullptr) {
      if (prev != nullptr) {
        prev->next = current->next;
      } else {
        head = current->next;
      }
      delete current->value;
      delete current;
      this->count--;
    }
  }

  int Reset() override {
    current = head;
    return 0;
  }

  int IsTabEnded() const override { return current == nullptr; }

  int GoNext() override {
    if (!IsTabEnded()) {
      current = current->next;
      return true;
    } else {
      return false;
    }
  }

  TKey GetKey() const override {
    if (current != nullptr) {
      return current->key;
    } else {
      return TKey();
    }
  }

  TValue GetValuePtr() const override {
    if (current != nullptr) {
      return *(current->value);
    } else {
      return TValue();
    }
  }

  ~ListTable() {
    current = head;
    while (current != nullptr) {
      Node<TKey, TValue>* next = current->next;
      delete current->value;
      delete current;
      current = next;
    }
  }
};
