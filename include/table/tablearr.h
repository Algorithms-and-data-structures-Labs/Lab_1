#pragma once
#include <table/tablerec.h>

template <typename TKey, typename TValue>
class ArrayTable : public Table<TKey, TValue> {
 private:
  size_t currentIndex;
  struct TabRec {
    TKey key;
    TValue* value;
  };
  vector<TabRec> data{};

 public:
  size_t size() const noexcept { return data.size(); }
  TValue& operator[](size_t pos) { return data[pos].value; }
  ArrayTable() : currentIndex(0) { count = 0; }

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
    currentIndex = data.size() - 1;
  }

  void Delete(TKey key) override {
    for (size_t i = 0; i < data.size(); i++)
      if (data[i].key == key) {
        data[i] = data[data.size() - 1];
        data.pop_back();
        return;
      }
    this->count--;
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
