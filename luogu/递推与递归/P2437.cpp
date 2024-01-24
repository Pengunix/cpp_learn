// AC fib
#include "../../utils/普通高精度.cpp"
#include <iostream>
using namespace std;
using ll = long long;
const int N = 1010;
Int f[N] = {0, 1, 1};

int main() {
  int m, n;
  cin >> m >> n;
  for (int i = 3; i <= n - m + 1; ++i)
    f[i] = f[i - 1] + f[i - 2];
  cout << f[n - m + 1];
  return 0;
}