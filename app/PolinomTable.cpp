#include <table/alltable.h>

#include "Polinom/TPolinom.h"

void GetTablest(AllTable<string, std::vector<int>> tab) {
  system("CLS");
  std::vector<std::vector<std::vector<int>>> pols;
  std::vector<std::vector<std::string>> keys;
  int c = 0;
  for (tab.Reset(); !tab.IsTabEnded(); tab.GoNext()) {
    std::vector<std::vector<int>> a;
    std::vector<string> a1;
    a = tab.GetValuePtr();
    a1 = tab.GetKey();
    pols.push_back(a);
    keys.push_back(a1);
    c++;
  }
  for (int i = 0; i < 6; i++) {
    switch (i) {
      case 0:
        std::cout << "ArrayTable"
                  << "\n\n";
        break;
      case 1:
        std::cout << "ListTable"
                  << "\n\n";
        break;
      case 2:
        std::cout << "ListHashTable"
                  << "\n\n";
        break;
      case 3:
        std::cout << "OpenAddrHashTable"
                  << "\n\n";
        break;
      case 4:
        std::cout << "SortArrayTable"
                  << "\n\n";
        break;
      case 5:
        std::cout << "TreeTable"
                  << "\n\n";
        break;
    }
    for (int j = 0; j < c; j++) {
      TPolinom pol(pols[j][i]);
      std::cout << keys[j][i] << "  " << pol.ToString() << "     ";
      std::cout << "\n\n";
    }
  }
}

int CheckMenu() {
  std::cout << "1. Add Polinom"
            << "\n"
            << "2. Find Polinom"
            << "\n"
            << "3. Delete Polinom"
            << "\n"
            << "4. Sub Polinom"
            << "\n"
            << "5. Mult on Const"
            << "\n"
            << "6. Calculate in point"
            << "\n"
            << "7. EXIT"
            << "\n";
  int i;
  cin >> i;
  return i;
}

int main() {
  AllTable<string, std::vector<int>> tab;
  std::cout << "Welcome to the program for working with polynomials. The "
               "possible operations for working with tables are presented "
               "below";
  std::cout << "\n";
  std::cout << "You should choose one of them.";
  std::cout << "\n";
  int menu;
  menu = CheckMenu();
  while (menu != 7) {
    switch (menu) {
      case 1: {
        std::cout << "Enter the key";
        std::cout << "\n";
        std::string key;
        cin >> key;
        std::cout << "\n";
        std::string str;
        std::cout << "Enter the polynomial";
        std::cout << "\n";
        cin >> str;
        std::vector<int> pol;
        for (size_t i = 0; i < str.length(); i += 4) {
          pol.push_back(str[i] - '0');
          pol.push_back((str[i + 1] - '0') * 100 + (str[i + 2] - '0') * 10 +
                        (str[i + 3] - '0'));
        }
        tab.Insert(key, pol);
        GetTablest(tab);
        std::cout << "\n\n";
        menu = CheckMenu();
        break;
      }
      case 2: {
        std::cout << "Enter the key";
        std::cout << "\n";
        std::string key;
        cin >> key;
        std::cout << "\n";
        std::vector<std::vector<int>*> a = tab.Find(key);
        std::vector<std::vector<int>> b;
        for (int i = 0; i < 6; i++) b.push_back(*a[i]);
        GetTablest(tab);
        std::cout << "\n\n";
        TPolinom pol(b[0]);
        std::cout << "Your result:  " << pol.ToString();
        std::cout << "\n\n\n";
        menu = CheckMenu();
        break;
      }
      case 3: {
        std::cout << "Enter the key";
        std::cout << "\n";
        std::string key;
        cin >> key;
        std::cout << "\n";
        tab.Delete(key);
        GetTablest(tab);
        std::cout << "\n\n";
        menu = CheckMenu();
        break;
      }
      case 4: {
        std::cout << "Enter the first key";
        std::cout << "\n";
        std::string key1;
        cin >> key1;
        std::cout << "\n";
        std::cout << "Enter the second key";
        std::cout << "\n";
        std::string key2;
        cin >> key2;
        std::cout << "\n";
        std::vector<std::vector<int>*> a = tab.Find(key1);
        std::vector<std::vector<int>> b;
        std::vector<std::vector<int>*> a1 = tab.Find(key2);
        std::vector<std::vector<int>> b1;
        for (int i = 0; i < 6; i++) b.push_back(*a[i]);
        for (int i = 0; i < 6; i++) b1.push_back(*a1[i]);
        TPolinom pol1(b[0]);
        TPolinom pol2(b1[0]);
        TPolinom pol(b1[0]);
        pol = pol1.AddPolinom(pol2);
        GetTablest(tab);
        std::cout << "\n\n";
        std::cout << "Your result:  " << pol.ToString();
        std::cout << "\n\n\n";
        menu = CheckMenu();
        break;
      }
      case 5: {
        std::cout << "Enter the key";
        std::cout << "\n";
        std::string key;
        cin >> key;
        std::cout << "\n";
        std::cout << "Enter the coef";
        std::cout << "\n";
        int coef;
        cin >> coef;
        std::cout << "\n";
        std::vector<std::vector<int>*> a = tab.Find(key);
        std::vector<std::vector<int>> b;
        for (int i = 0; i < 6; i++) b.push_back(*a[i]);
        TPolinom pol(b[0]);
        pol = pol * coef;
        GetTablest(tab);
        std::cout << "\n\n";
        std::cout << "Your result:  " << pol.ToString();
        std::cout << "\n\n\n";
        menu = CheckMenu();
        break;
      }
      case 6: {
        std::cout << "Enter the key";
        std::cout << "\n";
        std::string key;
        cin >> key;
        std::cout << "\n";
        std::cout << "Enter the coefs";
        std::cout << "\n";
        int x;
        int y;
        int z;
        cin >> x >> y >> z;
        std::cout << "\n";
        std::vector<std::vector<int>*> a = tab.Find(key);
        std::vector<std::vector<int>> b;
        for (int i = 0; i < 6; i++) b.push_back(*a[i]);
        TPolinom pol(b[0]);
        double Point = pol.Evaluate(x, y, z);
        // GetTablest(tab);
        std::cout << "\n\n";
        std::cout << "Your result:  " << Point;
        std::cout << "\n\n\n";
        menu = CheckMenu();
        break;
      }
    }
  }
  return 0;
}