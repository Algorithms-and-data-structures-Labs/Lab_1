#pragma once
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "List/THeadList.h"
#include "Polinom/TMonom.h"

const int nonDisplayedZeros = 4;

class TPolinom : public THeadList<TMonom> {
 public:
  TPolinom();
  TPolinom(TPolinom& other);
  TPolinom(vector<int> a);
  TPolinom& operator=(TPolinom& other);
  TPolinom& operator+(TPolinom& q);
  void AddMonom(TMonom newMonom);
  TPolinom MultMonom(TMonom monom);
  TPolinom AddPolinom(TPolinom& other);
  TPolinom operator*(double coef);
  TPolinom operator*(TPolinom& other);
  bool operator==(TPolinom& other);
  string ToString();
};

TPolinom::TPolinom() : THeadList<TMonom>::THeadList() { length = 0; }

TPolinom::TPolinom(TPolinom& other) {
  int sz = other.GetLength();
  other.Reset();
  TMonom start;
  start = other.GetCurrentItem();
  other.GoNext();
  InsertFirst(start);
  Reset();
  for (int i = 1; i < sz; i++) {
    TMonom a;
    a = other.GetCurrentItem();
    InsertNextCurrent(a);
    GoNext();
    other.GoNext();
  }
  Reset();
  other.Reset();
  pStop = nullptr;
}

TPolinom::TPolinom(vector<int> a) {
  pStop = nullptr;
  int sz1 = 2;
  int i1 = 1;
  int sz = static_cast<int>(a.size());
  TMonom start(a[0], a[1], a[2], a[3]);
  InsertFirst(start);
  Reset();
  TMonom mon;
  mon = GetCurrentItem();
  int ind = mon.checkMonom() % 1000;
  for (int i = 4; i < sz; i += 4) {
    int ind1 = a[i + 1] * 100 + a[i + 2] * 10 + a[i + 3];
    Reset();
    TMonom first;
    first = GetCurrentItem();
    int ind = first.checkMonom() % 1000;
    if (ind1 > ind) {
      InsertFirst(TMonom(a[i], a[i + 1], a[i + 2], a[i + 3]));
      sz1++;
    } else {
      while (ind1 < ind) {
      if (i1 < sz1) {
        GoNext();
        i1++;
        mon = GetCurrentItem();
        ind = mon.checkMonom() % 1000;
      } else {
        InsertLast(TMonom(a[i], a[i + 1], a[i + 2], a[i + 3])); sz1++; return;
       }
    }
    if (ind == ind1) {
      if (i1 == 1) {
        mon.SetCoef(mon.GetCoef() + a[i]);
        InsertFirst(mon);
        Reset();
        GoNext();
        DeleteCurrent();
	  }
      else {
        mon.SetCoef(mon.GetCoef() + a[i]);
        DeleteCurrent();
        InsertPrevCurrent(mon);
      }
    }
    else {
      InsertPrevCurrent(TMonom(a[i], a[i + 1], a[i + 2], a[i + 3])); sz1++;
    }
  }
  i1 = 1;
  }
  Reset();
}

TPolinom& TPolinom::operator=(TPolinom& other) {
  int sz = GetLength();
  Reset();
  for (int i = 0; i < sz - 1; i++) {
    DeleteFirst();
  }
  Reset();
  other.Reset();
  int sz1 = other.GetLength();
  for (int i = 0; i < sz1; i++) {
    TMonom a;
    a = other.GetCurrentItem();
    InsertNextCurrent(a);
    GoNext();
    other.GoNext();
  }
  DeleteFirst();
  Reset();
  other.Reset();
  return *this;
}

void TPolinom::AddMonom(TMonom m) {
  int sz = GetLength();
  int i = 0;
  Reset();
  TMonom mon;
  mon = GetCurrentItem();
  int ind = mon.checkMonom() % 1000;
  int ind1 = m.checkMonom() % 1000;
  if (ind1 > ind)
    InsertFirst(m);
  else {
    while (ind1 < ind) {
      if (i < sz) {
        GoNext();
        i++;
        mon = GetCurrentItem();
        ind = mon.checkMonom() % 1000;
      } else {
        InsertLast(m);
        return;
      }
    }
    if (ind  == ind1) {
      if (mon.GetCoef() + m.GetCoef() != 0) {
        mon.SetCoef(mon.GetCoef() + m.GetCoef());
        DeleteCurrent();
        InsertPrevCurrent(mon);
      }
      else { DeleteCurrent(); }
    }
  else {
    InsertPrevCurrent(m);
  }
  }
  Reset();
}

TPolinom TPolinom::MultMonom(TMonom monom) {
  TPolinom result;
  return result;
}

TPolinom& TPolinom::operator+(TPolinom& other) {
  TPolinom result(*this);
  result.AddPolinom(other);
  return result;
}

TPolinom TPolinom::AddPolinom(TPolinom& other) {
  TPolinom res(*this);
  int sz = other.GetLength();
  other.Reset();
  for (int i = 0; i < sz; i++) {
    TMonom a;
    a = other.GetCurrentItem();
    res.AddMonom(a);
    other.GoNext();
  }
  return res;
}

TPolinom TPolinom::operator*(double coef) {
  TPolinom result(*this);
  result.Reset();
  TMonom mon;
  int sz = result.GetLength();
  for (int i =0; i < sz; i++) {
    mon = result.GetCurrentItem();
    mon.SetCoef(mon.GetCoef() * coef);
    result.DeleteCurrent();
    result.InsertPrevCurrent(mon);
  }
  return result;
}

TPolinom TPolinom::operator*(TPolinom& other) {
  TPolinom result;
  return result;
}

bool TPolinom::operator==(TPolinom& other) {
  int sz = other.GetLength();
  if (this->GetLength() != other.GetLength()) {
    return false;
  }
  Reset();
  other.Reset();
  for (int i = 0; i < sz;i++) {
    TMonom a,b;
    a = other.GetCurrentItem();
    b = GetCurrentItem();
    GoNext();
    other.GoNext();
    if (a == b) {
    } else{
    return false;
    }
  }
  return true;
}


string TPolinom::ToString() {
  string result;
  int sz = GetLength();
  Reset();
  for (int i = 0; i < sz; i++) {
    TMonom a;
    a = GetCurrentItem();
    double A = a.GetCoef();
    std::ostringstream oss;
    oss << std::setprecision(5) << A;
    int ind = a.GetIndex();
    result += oss.str();
    result += "X";
    result += std::to_string((ind - ind % 100) / 100);
    result += "Y";
    result += std::to_string(((ind % 100) - (ind % 10)) / 10);
    result += "Z";
    result += std::to_string(ind % 10);
    if(i!=sz-1)
    result += " + ";
    if(i<sz-1)
    GoNext();
  }
  Reset();
  return result;
}
