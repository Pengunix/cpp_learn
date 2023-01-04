#include <iostream>
using namespace std;

template <typename T> void mySwap(T &a, T &b) {
  T temp = a;
  a = b;
  b = temp;
}

// 不同类型数组排序
// 选择排序
template <typename T> void mySort(T arr[], int len) {
  for (int i = 0; i < len; i++) {
    int max = i;
    for (int j = i + 1; j < len; j++) {
      if (arr[max] < arr[j]) {
        max = j;
      }
    }
    if (max != i) {
      mySwap(arr[max], arr[i]);
    }
  }
}

void test1() {
  char Achar[] = "abcd";
  mySort(Achar, sizeof(Achar) / sizeof(char));
  for (auto &i : Achar) {
    cout << i;
  }
  cout << "\n";

  int Aint[] = {1, 2, 4, 5, 2, 6, 7};
  mySort<int>(Aint, sizeof(Aint) / sizeof(int));
  for (auto &i : Aint) {
    cout << i;
  }
}

int main() { test1(); }
