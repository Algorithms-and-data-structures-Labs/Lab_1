#pragma once
#include <table/tablerec.h>

template <typename TKey, typename TValue>
struct TabRecorD {
  TKey key;
  TValue *value;
  TabRecorD(TKey k = TKey(), TValue *d = nullptr) : key(k), value(d) {}
};

template <typename TKey, typename TValue>
class OpenAddrHashTable : public Table<TKey, TValue> {
 public:
  virtual unsigned long HashFunc(const TKey key) {
    unsigned long hashval = 0;
    int len = key.size();
    for (int i = 0; i < len; i++) hashval = (hashval << 3) + key[i];
    return hashval;
  }

 private:
  int pos;
  TabRecorD<TKey, TValue> **rec;
  int tabsize;
  int freepos;
  int hashstep;
  TabRecorD<TKey, TValue> *mark;

 public:
  OpenAddrHashTable(int s, int step) : Table<TKey, TValue>() {
    rec = new TabRecorD<TKey, TValue> *[s];
    for (int i = 0; i < s; i++) {
      rec[i] = nullptr;
    }
    tabsize = s;
    hashstep = step;
    mark = new TabRecorD<TKey, TValue>(TKey(), nullptr);
  }

  ~OpenAddrHashTable() {
    for (int i = 0; i < tabsize; i++) {
      if (rec[i] != nullptr && rec[i] != mark) delete rec[i];
    }
    delete[] rec;
    delete mark;
  }

  bool IsFull() const override { return count == tabsize; }

  TValue *Find(TKey k) override {
    TabRecorD<TKey, TValue> *tmp = nullptr;
    freepos = -1;

    pos = HashFunc(k) % tabsize;
    for (int i = 0; i < tabsize; i++) {
      if (rec[pos] == nullptr)
        break;
      else if ((rec[pos] == mark) && (freepos == -1))
        freepos = pos;
      if (rec[pos]->key == k) {
        tmp = rec[pos];
        break;
      }
      pos = GetNextPos(pos);
    }
    if (freepos != -1) pos = freepos;

    if (tmp == nullptr) return nullptr;
    TValue *tms = tmp->value;
    return tms;
  }

  void Insert(TKey k, TValue d) override {
    if (IsFull()) return;
    if (Find(k) == nullptr) {
      TValue *newData = new TValue(d);
      rec[pos] = new TabRecorD<TKey, TValue>(k, newData);
      count++;
    }
  }

  void Delete(TKey k) override {
    if (Find(k) == nullptr) return;
    delete rec[pos];
    rec[pos] = mark;
    count--;
  }

  int Reset() override {
    pos = 0;
    while (!IsTabEnded()) {
      if (rec[pos] != nullptr && rec[pos] != mark)
        break;
      else
        pos++;
    }
    return IsTabEnded();
  }

  int IsTabEnded() const override { return count == tabsize; }

  int GoNext() override {
    if (!IsTabEnded()) {
      while (++pos < tabsize) {
        if (rec[pos] != nullptr && rec[pos] != mark) break;
      }
    }
    return IsTabEnded();
  }

  TKey GetKey() const override {
    if (rec[pos] != nullptr) return rec[pos]->key;
    return TKey();
  }

  TValue GetValuePtr() const override {
    if (rec[pos] != nullptr) return *(rec[pos]->value);
    return TValue();
  }

 private:
  int GetNextPos(int pos) { return (pos + hashstep) % tabsize; }
};
