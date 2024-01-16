#include <iostream>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
// 卡特兰数，进阶篇计数原理有讲
int main() {
  int n, h[20] = {1, 1};
  cin >> n;
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j < i; j++) {
      h[i] += h[j] * h[i - j - 1];
    }
  }
  cout << h[n];
  return 0;
}