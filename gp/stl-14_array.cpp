#include <iostream>
#include <array>
using namespace std;
using ll = long long;
const int N = 10;

array<int, N> a;

int f(int *a) {
  cout << a[0] << endl;
  return 0;
}

int main() {
  // 全部赋值为0
  a.fill(0);
  // 函数传参
  f(a.data());

  for (auto &i : a) {
    cout << i << endl;
  }
  
}