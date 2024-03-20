#pragma once
#include <iostream>

#include "List/TNode.h"
using namespace std;

template <class T>
class TList {
 protected:
  TNode<T>* pFirst;
  TNode<T>* pCurr;
  TNode<T>* pPrev;
  TNode<T>* pLast;
  TNode<T>* pStop;
  int length;

 public:
  TList();
  ~TList();
  int GetLength() { return length; }
  bool IsEmpty();
  void InsertFirst(T item);
  void InsertPCurrent(T item);
  void InsertNCurrent(T item);
  void InsertLast(T item);
  void DeleteFirst();
  void DeleteCurrent();
  void GoNext();
  void Reset();
  bool IsEnd();
  T GetCurrentItem();
  void SetCurrentItem(T item) { pCurr->val = item; }
};
template <class T>
TList<T>::TList() {
  pFirst = nullptr;
  pCurr = nullptr;
  pPrev = nullptr;
  pLast = nullptr;
  pStop = nullptr;
  length = 0;
}

template <class T>
TList<T>::~TList() {}

template <class T>
bool TList<T>::IsEmpty() {
  if (length == 0) return true;
  return false;
}

template <class T>
void TList<T>::InsertFirst(T item) {
  TNode<T>* nNode = new TNode<T>;
  nNode->val = item;
  nNode->pNext = pFirst;
  pFirst = nNode;
  if (length == 0) {
    pLast = pFirst;
    pStop = new TNode<T>;
    pStop->pNext = nullptr;
  }
  length++;
}

template <class T>
void TList<T>::InsertLast(T item) {
  TNode<T>* nNode = new TNode<T>;
  nNode->val = item;
  nNode->pNext = nullptr;
  if (length == 0) {
    pFirst = nNode;
    pStop = new TNode<T>;
    pStop->pNext = nullptr;
  } else {
    pLast->pNext = nNode;
  }
  pLast = nNode;
  length++;
}

template <class T>
void TList<T>::InsertPCurrent(T item) {
  TNode<T>* nNode = new TNode<T>;
  nNode->val = item;
  if (pCurr == pFirst) {
    nNode->pNext = pFirst;
    pFirst = nNode;
  } else {
    pPrev->pNext = nNode;
    nNode->pNext = pCurr;
  }
  length++;
}

template <class T>
void TList<T>::InsertNCurrent(T item) {
  TNode<T>* nNode = new TNode<T>;
  nNode->val = item;
  if (pCurr == pLast) {
    nNode->pNext = nullptr;
    pLast->pNext = nNode;
    pLast = nNode;
  } else {
    nNode->pNext = pCurr->pNext;
    pCurr->pNext = nNode;
  }
  length++;
}

template <class T>
void TList<T>::DeleteFirst() {
  if (pFirst != nullptr) {
    TNode<T>* temp = pFirst;
    pFirst = pFirst->pNext;
    delete temp;
    length--;
    if (length == 0) {
      pLast = nullptr;
      pStop = nullptr;
    }
  }
}

template <class T>
void TList<T>::DeleteCurrent() {
  if (pCurr != nullptr && pFirst != nullptr) {
    if (pCurr == pFirst) {
      DeleteFirst();
    } else {
      pPrev->pNext = pCurr->pNext;
      pCurr = pCurr->pNext;
      length--;
    }
    if (pCurr == pLast) {
      pLast = pPrev;
    }
    if (pCurr == pStop) {
      pStop = pPrev;
    }
  }
}

template <class T>
T TList<T>::GetCurrentItem() {
  if (length == 0) throw "len=0";
  if (pCurr == nullptr) return T();
  return pCurr->val;
}

template <class T>
void TList<T>::GoNext() {
  pPrev = pCurr;
  pCurr = pCurr->pNext;
}

template <class T>
void TList<T>::Reset() {
  pCurr = pFirst;
  pPrev = nullptr;
}

template <class T>
bool TList<T>::IsEnd() {
  if (pCurr->pNext == pStop) return true;
  return false;
}
