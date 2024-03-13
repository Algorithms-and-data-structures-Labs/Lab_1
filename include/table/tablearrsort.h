#pragma once
#include <table/tablerec.h>
#include <algorithm>
#include <iostream>
#include <locale>
#include <string>

template <typename TKey, typename TValue>
class SortArrayTable : public Table<TKey, TValue> {
 private:
  size_t currentIndex;

 public:
  SortArrayTable() : currentIndex(0) {}

  ~SortArrayTable() {
    for (auto& tab : data) {
      delete tab.value;
    }
  }

  bool IsFull() const override {
    if (count == TabMaxSize)
      return true;
    else
      return false;
  }

  TValue* Find(TKey key) override {
    for (auto& val : data)
      if (val.key == key) return val.value;
    return nullptr;
  }

 void Insert(TKey key, TValue value) override {
    TValue* newValue = new TValue(value);
    TabRec tab = {key, newValue};
    data.push_back(tab);
    this->count++;
    sort(data.begin(), data.end(),
         [](const TabRec& a, const TabRec& b) { return a.key < b.key; });
  }

  void Delete(TKey key) override {
    for (size_t i = 0; i < data.size(); i++)
      if (data[i].key == key) {
        data.erase(data.begin() + i);
        this->count--;
        return;
      }
  }

  int Reset() override {
    currentIndex = 0;
    return currentIndex;
  }

  int IsTabEnded() const override { return currentIndex >= data.size(); }

  int GoNext() override {
    currentIndex++;
    return currentIndex;
  }

  TKey GetKey() const override { return data[currentIndex].key; }

  TValue GetValuePtr() const override { return *data[currentIndex].value; }
};