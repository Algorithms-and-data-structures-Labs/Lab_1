#pragma once
#include <math.h>

#include <iostream>

using namespace std;
template <class T>
class TStack {
 protected:
  int size;
  int top;
  T* mas;

 public:
  TStack(int n = 1);
  TStack(TStack<T>& stack);
  ~TStack();
  void Push(T a);
  T Get();
  T TopView();
  int GetSize();
  int GetTop();
  bool IsFull();
  bool IsEmpty();
  void printstack();
  TStack& operator=(const TStack<T>& stack);
  friend ostream& operator<<(ostream& ostr, const TStack<T>& A);
  friend istream& operator>>(istream& istr, TStack<T>& A);
};

template <class T>
ostream& operator<<(ostream& ostr, const TStack<T>& A) {
  for (int i = 0; i < A.top; i++) {
    ostr << A.mas[i] << "\n";
    ostr << endl;
  }
  return ostr;
}

template <class T>
istream& operator>>(istream& istr, TStack<T>& A) {
  for (int i = 0; i < A.size; i++) {
    istr >> A.mas[i];
  }
  return istr;
}

template <class T>
void TStack<T>::Push(T a) {
  if (IsFull()) throw "StackFull";
  this->mas[top] = a;
  top++;
}

template <class T>
T TStack<T>::Get() {
  if (IsEmpty()) throw "StackEmpty";
  top--;
  return mas[top];
}

template <class T>
TStack<T>::TStack(int n) {
  if (n < 0)
    throw "Error size";
  else if (n == 0) {
    size = 0;
    top = 0;
  } else {
    size = n;
    mas = new T[n];
    top = 0;
  }
}

template <class T>
void TStack<T>::printstack() {
  for (int i = top - 1; i >= 0; i--) cout << " " << mas[i];
}

template <class T>
TStack<T>::TStack(TStack<T>& stack) {
  this.size = stack.size;
  T* mas = new T[this.size];
  for (int i = 0; i < this.size i++) mas[i] = stack.mas[i];
  this->top = stack.top;
}

template <class T>
TStack<T>::~TStack() {
  delete[] mas;
  top = 0;
  size = 0;
}

template <class T>
bool TStack<T>::IsEmpty() {
  return (top == 0);
}

template <class T>
bool TStack<T>::IsFull() {
  return (top >= size);
}

template <class T>
int TStack<T>::GetSize() {
  return size;
}

template <class T>
int TStack<T>::GetTop() {
  return top;
}

template <class T>
T TStack<T>::TopView() {
  return mas[top];
}

template <class T>
TStack<T>& TStack<T>::operator=(const TStack<T>& a) {
  if (this != &a) {
    delete[] mas;
    top = a.top;
    size = a.size;
    mas = new T[size];
    for (int i = 0; i < size; i++) mas[i] = a.mas[i];
  }
  return *this;
}
