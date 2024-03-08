#pragma once
#include <iostream>
#include <locale>
#include <string>
#include <vector>

using namespace std;

#define TabMaxSize 100
template <typename TKey, typename TValue>
class Unorderable {
 protected:
  struct TabRec {
    TKey key;
    TValue* value;
  };
  vector<TabRec> data{};

 public:
  Unorderable() = default;
  size_t size() const noexcept { return data.size(); }
  TValue& operator[](size_t pos) { return data[pos].value; }
};

template <typename TKey, typename TValue>
class Table : public Unorderable<typename TKey, typename TValue> {
 protected:
  int count;

 public:
  int GetDataCount() const { return count; }
  bool IsEmpty() const {
    if (count == 0)
      return true;
    else
      return false;
  }
  virtual bool IsFull() const = 0;
  virtual TValue* Find(TKey key) = 0;
  virtual void Insert(TKey key, TValue value) = 0;
  virtual void Delete(TKey key) = 0;
  virtual int Reset(void) = 0;
  virtual int IsTabEnded(void) const = 0;
  virtual int GoNext(void) = 0;
  virtual TKey GetKey(void) const = 0;
  virtual TValue GetValuePtr(void) const = 0;
  friend ostream& operator<<(ostream& os, Table& tab) {
    cout << "Table printing" << endl;
    for (tab.Reset(); !tab.IsTabEnded(); tab.GoNext()) {
      os << " Key: " << tab.GetKey() << " Val: " << *tab.GetValuePtr() << endl;
    }
    return os;
  }
};
