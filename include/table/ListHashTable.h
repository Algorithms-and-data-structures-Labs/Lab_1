#pragma once
#include <table/tablerec.h>

#include <iostream>
#include <list>
#include <string>

template <typename TKey, typename TValue>
struct TabRecord {
  TKey key;
  TValue *value;
  TabRecord(TKey k = TKey(), TValue *d = nullptr) : key(k), value(d) {}
};
template <typename TKey, typename TValue>
class ListHashTable : public Table<TKey, TValue> {
 public:
  virtual unsigned long HashFunc(const TKey key) {
    unsigned long hashval;
    hashval = 0;
    return hashval % tabsize;
  }

 protected:
  int tabsize;
  int CurList;
  std::list<TabRecord<TKey, TValue>> *pList;
  typename std::list<TabRecord<TKey, TValue>>::iterator startChain;

 public:
  ListHashTable(int size) {
    pList = new std::list<TabRecord<TKey, TValue>>[size];
    tabsize = size;
    CurList = 0;
    for (int i = 0; i < tabsize; i++)
      pList[i] = std::list<TabRecord<TKey, TValue>>();
  }

  ~ListHashTable() { delete[] pList; }
  bool IsFull() const override { return false; }

  TValue *Find(TKey k) override {
    TabRecord<TKey, TValue> *tmp = nullptr;
    CurList = HashFunc(k) % tabsize;
    std::list<TabRecord<TKey, TValue>> *lst = pList + CurList;
    for (auto &rec : *lst) {
      if (rec.key == k) {
        tmp = new TabRecord<TKey, TValue>(rec.key, rec.value);
        break;
      }
    }
    if (tmp == nullptr) return nullptr;
    TValue *tms = tmp->value;
    return tms;
  }

  void Insert(TKey k, TValue pVal) override {
    CurList = HashFunc(k) % tabsize;
    std::list<TabRecord<TKey, TValue>> *lst = pList + CurList;

    TValue *val = new TValue(pVal);
    TabRecord<TKey, TValue> record(k, val);

    lst->push_back(record);
  }

  void Delete(TKey k) override {
    CurList = HashFunc(k) % tabsize;
    std::list<TabRecord<TKey, TValue>> *lst = pList + CurList;
    for (auto it = lst->begin(); it != lst->end(); ++it) {
      if (it->key == k) {
        it = lst->erase(it);
        return;
      }
    }
  }

  int Reset() override {
    CurList = 0;
    while (pList[CurList].empty()) {
      CurList++;
      if (IsTabEnded()) {
        return false;
      }
    }
    startChain = pList[CurList].begin();
    return !IsTabEnded();
  }

  int IsTabEnded() const override { return CurList >= tabsize; }

  int GoNext() override {
    startChain++;
    if (startChain != pList[CurList].end()) {
      return !IsTabEnded();
    }
    CurList++;
    while (pList[CurList].size() == 0 && !IsTabEnded()) {
      CurList++;
    }
    if (IsTabEnded()) {
      return false;
    }
    startChain = pList[CurList].begin();
    return !IsTabEnded();
  }

  TKey GetKey() const override {
    if (CurList >= tabsize) {
      throw std::out_of_range("No key at this position");
    }
    return pList[CurList].back().key;
  }

  TValue GetValuePtr() const override {
    if (CurList == tabsize) {
      throw std::out_of_range("No value at this position");
    }
    return *(pList + CurList)->back().value;
  }
};
