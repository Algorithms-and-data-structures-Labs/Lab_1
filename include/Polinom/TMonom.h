#pragma once
struct TMonom {
  double coef;
  int index;

  TMonom() {
    coef = 0;
    index = 0;
  }

  TMonom(double _coef, int deg) {
    coef = _coef;
    index = deg;
  }

  void SetCoef(int cval) { coef = cval; }
  int GetCoef(void) { return coef; }

  void SetIndex(int ival) { index = ival; }
  int GetIndex(void) { return index; }

  void operator=(const TMonom& other) {
    coef = other.coef;
    index = other.index;
  }

  bool operator==(const TMonom& other) {
    if (coef != other.coef) return false;
    if (index != other.index) return false;
    return true;
  }

  bool operator>(const TMonom& other) {
    if (index < other.index) return false;
    if (coef < other.coef) return false;
    return true;
  }

  bool operator<(const TMonom& other) {
    if (index > other.index) return false;
    if (coef > other.coef) return false;
    return true;
  }
  int IMonom() { return coef * 1000 + index; }
};
