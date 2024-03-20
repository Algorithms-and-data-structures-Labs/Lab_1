#pragma once
#include "List/TList.h"
using namespace std;

template <class T>
class THeadList : public TList<T> {
 protected:
  TNode<T>* pHead;

 public:
  THeadList();
  ~THeadList();
  void InsertFirst(T item);
  void DeleteFirst();
};

template <class T>
THeadList<T>::THeadList() {
  pHead = new TNode<T>{};
  this->pFirst = pHead->pNext;
  this->pStop = new TNode<T>{};
  this->pLast = this->pStop;
  this->pCurr = this->pFirst;
  this->length = 0;
}

template <class T>
THeadList<T>::~THeadList() {}

template <class T>
void THeadList<T>::InsertFirst(T item) {
  TNode<T>* nNode = new TNode<T>{item, nullptr};
  nNode->pNext = this->pFirst;
  this->pFirst = nNode;
  this->length++;
}

template <class T>
void THeadList<T>::DeleteFirst() {
  if (this->IsEmpty()) {
    throw "List is empty";
  }
  TNode<T>* temp = this->pFirst;
  this->pFirst = this->pFirst->pNext;
  delete temp;
  this->length--;
}
