#include <table/alltable.h>

#include "Polinom/TPolinom.h"

#include <ctime>
#include <random>
#include <chrono>

vector<int> convertToVector(const std::string& inputString) {
  vector<int> resultVector;
  string temp;
  int digitCount = 0;
  bool flag = true;
  for (char c : inputString) {
    temp += c;
    digitCount++;
    if (flag == true) {
      resultVector.push_back(std::stoi(temp));
      temp.clear();
      digitCount = 0;
      flag = false;
    } else {
      if (digitCount == 3) {
        resultVector.push_back(std::stoi(temp));
        temp.clear();
        digitCount = 0;
        flag = true;
      }
    }
  }
  return resultVector;
}

string generateRandomNumber() {
  random_device rd;
  mt19937 gen(rd());

  static const int minStringLength = 4;
  static const int maxStringLength = 12;

  uniform_int_distribution<> lengthDis(minStringLength / 4,
                                            maxStringLength / 4);
  int length = lengthDis(gen) * 4;

  std::uniform_int_distribution<> digitDis(1, 9);
  std::string result;
  for (int i = 0; i < length; ++i) {
    result += std::to_string(digitDis(gen));
  }
  return result;
}

string generateRandomString() {
  static const std::string characters =
      "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
  static const int minLength = 5;
  static const int maxLength = 9;

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> lengthDis(minLength, maxLength);
  int length = lengthDis(gen);

  std::uniform_int_distribution<> charDis(0, characters.size() - 1);
  std::string randomString;
  for (int i = 0; i < length; ++i) {
    randomString += characters[charDis(gen)];
  }
  return randomString;
}

int main() {
  ListTable<string, string> listTable;
  ArrayTable<string, string> arrayTable;
  TreeTable<string, string> treeTable;
  ListHashTable<string, string> listhashTable(25);
  OpenAddrHashTable<string, string> openAddrHashTable(25, 2);
  SortArrayTable<string, string> sortArrayTable;
  const int tableSize = 10000;
  string key;
  TPolinom value, value1;
  string s1;
  vector<int> v;
  for (int i = 0; i < tableSize; i++) {
    key = generateRandomString();
    s1 = generateRandomNumber();
    v = convertToVector(s1);
    value = TPolinom(v);

    if (i == tableSize / 2) {
      listTable.Insert("404", "69");
      arrayTable.Insert("404", "69");
      treeTable.Insert("404", "69");
      listhashTable.Insert("404", "69");
      openAddrHashTable.Insert("404", "69");
      sortArrayTable.Insert("404", "69");
    } else {
      listTable.Insert(key, s1);
      arrayTable.Insert(key, s1);
      treeTable.Insert(key, s1);
      listhashTable.Insert(key, s1);
      openAddrHashTable.Insert(key, s1);
      sortArrayTable.Insert(key, s1);
    }
  }
  vector a = {1, 000};
  TPolinom p(a);

  auto start = std::chrono::steady_clock::now();
  arrayTable.Insert(generateRandomString(), "123");
  auto end = std::chrono::steady_clock::now();
  std::cout << "Time taken for insertion in ArrayTable: "
            << std::chrono::duration_cast<std::chrono::microseconds>(end -
                                                                     start)
                   .count()
            << " microseconds" << std::endl;

  start = std::chrono::steady_clock::now();
  listTable.Insert(generateRandomString(), "123");
  end = std::chrono::steady_clock::now();
  std::cout << "Time taken for insertion in ListTable: "
            << std::chrono::duration_cast<std::chrono::microseconds>(end -
                                                                     start)
                   .count()
            << " microseconds" << std::endl;

  start = std::chrono::steady_clock::now();
  treeTable.Insert(generateRandomString(), "123");
  end = std::chrono::steady_clock::now();
  std::cout << "Time taken for insertion in treeTable: "
            << std::chrono::duration_cast<std::chrono::microseconds>(end -
                                                                     start)
                   .count()
            << " microseconds" << std::endl;

  start = std::chrono::steady_clock::now();
  listhashTable.Insert(generateRandomString(), "123");
  end = std::chrono::steady_clock::now();
  std::cout << "Time taken for insertion in listhashTable: "
            << std::chrono::duration_cast<std::chrono::microseconds>(end -
                                                                     start)
                   .count()
            << " microseconds" << std::endl;

  start = std::chrono::steady_clock::now();
  openAddrHashTable.Insert(generateRandomString(), "123");
  end = std::chrono::steady_clock::now();
  std::cout << "Time taken for insertion in openAddrHashTable: "
            << std::chrono::duration_cast<std::chrono::microseconds>(end -
                                                                     start)
                   .count()
            << " microseconds" << std::endl;

  start = std::chrono::steady_clock::now();
  sortArrayTable.Insert(generateRandomString(), "123");
  end = std::chrono::steady_clock::now();
  std::cout << "Time taken for insertion in sortArrayTable: "
            << std::chrono::duration_cast<std::chrono::microseconds>(end -
                                                                     start)
                   .count()
            << " microseconds" << std::endl;
  std::cout << std::endl;




  //start = std::chrono::steady_clock::now();
  //arrayTable.Delete("404");
  //end = std::chrono::steady_clock::now();
  //std::cout << "Time taken for deletion in arrayTable: "
  //          << std::chrono::duration_cast<std::chrono::milliseconds>(end -
  //                                                                   start)
  //                 .count()
  //          << " milliseconds" << std::endl;
  //start = std::chrono::steady_clock::now();
  //listTable.Delete("404");
  //end = std::chrono::steady_clock::now();
  //std::cout << "Time taken for deletion in listTable: "
  //          << std::chrono::duration_cast<std::chrono::milliseconds>(end -
  //                                                                   start)
  //                 .count()
  //          << " milliseconds" << std::endl;
  //start = std::chrono::steady_clock::now();
  //treeTable.Delete("404");
  //end = std::chrono::steady_clock::now();
  //std::cout << "Time taken for deletion in treeTable: "
  //          << std::chrono::duration_cast<std::chrono::milliseconds>(end -
  //                                                                   start)
  //                 .count()
  //          << " milliseconds" << std::endl;
  //start = std::chrono::steady_clock::now();
  //listhashTable.Delete("404");
  //end = std::chrono::steady_clock::now();
  //std::cout << "Time taken for deletion in listhashTable: "
  //          << std::chrono::duration_cast<std::chrono::milliseconds>(end -
  //                                                                   start)
  //                 .count()
  //          << " milliseconds" << std::endl;
  //start = std::chrono::steady_clock::now();
  //openAddrHashTable.Delete("404");
  //end = std::chrono::steady_clock::now();
  //std::cout << "Time taken for deletion in openAddrHashTable: "
  //          << std::chrono::duration_cast<std::chrono::milliseconds>(end -
  //                                                                   start)
  //                 .count()
  //          << " milliseconds" << std::endl;
  //start = std::chrono::steady_clock::now();
  //sortArrayTable.Delete("404");
  //end = std::chrono::steady_clock::now();
  //std::cout << "Time taken for deletion in SortArrayTable: "
  //          << std::chrono::duration_cast<std::chrono::milliseconds>(end -
  //                                                                   start)
  //                 .count()
  //          << " milliseconds" << std::endl;


  start = std::chrono::steady_clock::now();
  arrayTable.Find("404");
  end = std::chrono::steady_clock::now();
  std::cout << "Time taken for search in ArrayTable: "
            << std::chrono::duration_cast<std::chrono::microseconds>(end -
                                                                     start)
                   .count()
            << " microseconds" << std::endl;

  start = std::chrono::steady_clock::now();
  listTable.Find("404");
  end = std::chrono::steady_clock::now();
  std::cout << "Time taken for search in listTable: "
            << std::chrono::duration_cast<std::chrono::microseconds>(end -
                                                                     start)
                   .count()
            << " microseconds" << std::endl;

  start = std::chrono::steady_clock::now();
  treeTable.Find("404");
  end = std::chrono::steady_clock::now();
  std::cout << "Time taken for search in treeTable: "
            << std::chrono::duration_cast<std::chrono::microseconds>(end -
                                                                     start)
                   .count()
            << " microseconds" << std::endl;

  start = std::chrono::steady_clock::now();
  listhashTable.Find("404");
  end = std::chrono::steady_clock::now();
  std::cout << "Time taken for search in listhashTable: "
            << std::chrono::duration_cast<std::chrono::microseconds>(end -
                                                                     start)
                   .count()
            << " microseconds" << std::endl;

  start = std::chrono::steady_clock::now();
  openAddrHashTable.Find("404");
  end = std::chrono::steady_clock::now();
  std::cout << "Time taken for search in openAddrHashTable: "
            << std::chrono::duration_cast<std::chrono::microseconds>(end -
                                                                     start)
                   .count()
            << " microseconds" << std::endl;

  start = std::chrono::steady_clock::now();
  sortArrayTable.Find("404");
  end = std::chrono::steady_clock::now();
  std::cout << "Time taken for search in sortArrayTable: "
            << std::chrono::duration_cast<std::chrono::microseconds>(end -
                                                                     start)
                   .count()
            << " microseconds" << std::endl;

  return 0;
}