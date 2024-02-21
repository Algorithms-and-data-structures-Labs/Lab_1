#pragma once

struct TMonom {
  double coef;
  int index;

  TMonom() {
    coef = 0;
    index = 0;
  }

  TMonom(double coef1, int degX, int degY, int degZ) {
    coef = coef1;
    index = degX * 100 + degY * 10 + degZ;
  }

  void SetCoef(int cval) { coef = cval; }
  int GetCoef() { return coef; }
  void SetIndex(int ival) { index = ival; }
  int GetIndex() { return index; }
  bool operator==(const TMonom& other) {
    if (coef != other.coef) return false;
    if (index != other.index) return false;
    return true;
  }
  void operator=(const TMonom& other) {
    coef = other.coef;
    index = other.index;
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
  int checkMonom() { return coef * 1000 + index;}
};
