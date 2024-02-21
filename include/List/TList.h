#pragma once
#include <iostream>

#include "List/TNode.h"

using namespace std;

template<class T>
class TList {
 protected:
  TNode<T>* pFirst;
  TNode<T>* pCurrent;
  TNode<T>* pPrevious;
  TNode<T>* pLast;
  TNode<T>* pStop;
  int length;

 public:
  TList();
  ~TList();
  int GetLength() { return length; }
  bool IsEmpty();
  void InsertFirst(T item);
  void InsertPrevCurrent(T item);
  void InsertNextCurrent(T item);
  void InsertLast(T item);
  void DeleteFirst();
  void DeleteCurrent();
  void GoNext();
  void Reset();
  bool IsEnd();
  T GetCurrentItem();
  void SetCurrentItem(T item) { pCurrent->value = item; }
};
template <class T>
TList<T>::TList() {
  pFirst=nullptr; 
  pCurrent = nullptr;
  pPrevious = nullptr;
  pLast = nullptr;
  pStop = nullptr;
  length=0;
}

template <class T>
TList<T>::~TList() {}

template <class T>
bool TList<T>::IsEmpty() {
  if(length == 0) return true;
  return false;
}

template <class T>
void TList<T>::InsertFirst(T item) {
  TNode<T>* newNode = new TNode<T>;
  newNode->value = item;
  newNode->pNext = pFirst;
  pFirst = newNode;
  if (length == 0) {
    pLast = pFirst;
	pStop = new TNode<T>;
	pStop->pNext = nullptr;
  }
  length++;
}

template <class T>
void TList<T>::InsertLast(T item) {
  TNode<T>* newNode = new TNode<T>;
  newNode->value = item;
  newNode->pNext = nullptr;
  if (length == 0) {
	pFirst = newNode;
	pStop = new TNode<T>;
	pStop->pNext = nullptr;
  }
  else {
    pLast->pNext = newNode;
  }
  pLast = newNode;
  length++;
}

template <class T>
void TList<T>::InsertPrevCurrent(T item) {
  TNode<T>* newNode = new TNode<T>;
  newNode->value = item;
  if (pCurrent == pFirst) {
	newNode->pNext = pFirst;
	pFirst = newNode;
  }
  else {
	pPrevious->pNext = newNode;
	newNode->pNext = pCurrent;
  }
  length++;
}

template <class T>
void TList<T>::InsertNextCurrent(T item) {
  TNode<T>* newNode = new TNode<T>;
  newNode->value = item;
  if (pCurrent == pLast) {
	newNode->pNext = nullptr;
	pLast->pNext = newNode;
	pLast = newNode;
  }
  else {
	newNode->pNext = pCurrent->pNext;
	pCurrent->pNext = newNode;
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
  if (pCurrent != nullptr && pFirst != nullptr) {
	if (pCurrent == pFirst) {
      DeleteFirst();
	}
    else {
      pPrevious->pNext = pCurrent->pNext;
      pCurrent= pCurrent->pNext;
      length--;
	}
	if (pCurrent == pLast) {
	pLast = pPrevious;
	}
	if (pCurrent == pStop) {
	  pStop = pPrevious;
	}
  }
}

template <class T>
T TList<T>::GetCurrentItem() {
  if (length == 0) throw"len=0";
  if (pCurrent == nullptr) return T();
  return pCurrent->value;
}

template <class T>
void TList<T>::Reset() {
  pCurrent = pFirst;
  pPrevious = nullptr;
}

template <class T>
void TList<T>::GoNext() {
  pPrevious = pCurrent;
  pCurrent = pCurrent->pNext;
}

template <class T>
bool TList<T>::IsEnd() {
  if(pCurrent->pNext==pStop) return true;
  return false;
}
