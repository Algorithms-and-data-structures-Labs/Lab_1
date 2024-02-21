#pragma once
#include "TList.h"
using namespace std;


template<class T>
class THeadList : public TList<T>
{
protected:
	TNode<T>* pHead;  // заголовок, pFirst - звено за pHead
public:
	THeadList();
	~THeadList();
	void InsertFirst(T item); // вставка звеньев после заголовка
	void InsertLast(T item);
	void DeleteFirst(); // удалить первое звено
};

template<class T>
THeadList<T>::THeadList()
{
	pHead = new TNode<T>{};
	this->pFirst = pHead->pNext;
	this->pStop = new TNode<T>{};
	this->pLast = this->pStop;
	this->pCurrent = this->pFirst;
	this->length = 0;
}

template<class T>
THeadList<T>::~THeadList()
{
}

template <class T>
void THeadList<T>::InsertFirst(T item)
{
	TNode<T>* newNode = new TNode<T>{ item, nullptr };
	newNode->pNext = this->pFirst;
	this->pFirst = newNode;
	this->length++;
}

template <class T>
void THeadList<T>::InsertLast(T item)
{
	TNode<T>* newNode = new TNode<T>{ item, nullptr };
	this->pLast = newNode;
	this->length++;
}

template <class T>
void THeadList<T>::DeleteFirst()
{
	if (this->IsEmpty()) {
		throw "List is empty, nothing to delete.";
	}
	TNode<T>* temp = this->pFirst;
	this->pFirst = this->pFirst->pNext;
	delete temp;
	this->length--;
}