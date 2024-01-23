// AC python也过了
#include <iostream>
#include "../../utils/普通高精度.cpp"
using namespace std;
using ll = long long;
const int N = 2e5 + 10;

int main() {
  Int ans(0), fac(1);
  int m;
  cin >> m;
  for (int i = 1; i <= m; i++) {
    fac = fac * i;
    ans = ans + fac;
  }
  ans.print();
}