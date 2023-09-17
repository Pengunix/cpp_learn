#include <bitset>
#include <iostream>
using namespace std;
using ll = long long;

// 数字二进制1的个数
int f(int x) {
  int res = 0;
  while (x) {
    if (x & 1)
      res++;
    x >>= 1;
  }
  return res;
}

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int x;

    cin >> x;

    cout << f(x) << '\n';
  }
}