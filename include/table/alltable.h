#pragma once
#include <table/tablearr.h>
#include <table/ListTable.h>

#include <iostream>
#include <locale>
#include <string>
#include <algorithm>
#include <vector>

#define MaxSize 100
template <typename TKey, typename TValue>
class AllTable {
 private:
  std::vector<Table<TKey, TValue>*> tables;
  int count;
 public:
  AllTable() {
    count = 0;
    tables.push_back(new ArrayTable<TKey, TValue>());
    tables.push_back(new ListTable<TKey, TValue>());
    tables.push_back(new ListTable<TKey, TValue>());
    tables.push_back(new ListTable<TKey, TValue>());
    tables.push_back(new ListTable<TKey, TValue>());
    tables.push_back(new ListTable<TKey, TValue>());
  }

  int GetDataCount() const { return count; }

  bool IsEmpty() const {
    if (count == 0)
      return true;
    else
      return false;
  }

  bool IsFull() const {
    if (count == MaxSize)
      return true;
    else
      return false;
  }

  std::vector<TValue*> Find(TKey key) {
    std::vector<TValue*> a;
    for (int i = 0;i < 6;i++) a.push_back(tables[i]->Find(key));
    return a;
  }

  void Insert(TKey key, TValue value) {
    for (int i = 0; i < 6; i++) tables[i]->Insert(key, value);
    count++;
  }

  void Delete(TKey key) {
    for (int i = 0; i < 6; i++) tables[i]->Delete(key);
    count--;
  }

  std::vector<int> Reset() {
    std::vector<int> a;
    for (int i = 0; i < 6; i++) a.push_back(tables[i]->Reset());
    return a;
  }

  std::vector<int> IsTabEnded() const {
    std::vector<int> a;
    for (int i = 0; i < 6; i++) a.push_back(tables[i]->IsTabEnded());
    return a;
  }

  std::vector<int> GoNext() {
    std::vector<int> a;
    for (int i = 0; i < 6; i++) a.push_back(tables[i]->GoNext());
    return a;
  }

  std::vector<TKey> GetKey() const {
    std::vector<TKey> a;
    for (int i = 0; i < 6; i++) a.push_back(tables[i]->GetKey());
    return a;
  }

  std::vector<TValue> GetValuePtr() const {
    std::vector<TValue> a;
    for (int i = 0; i < 6; i++) a.push_back(tables[i]->GetValuePtr());
    return a;
  }
};
