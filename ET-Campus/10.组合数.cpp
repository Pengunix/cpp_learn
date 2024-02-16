#include <iostream>
using namespace std;
using ll = long long;
ll p = 1e9 + 7;
const int N = 2023;

ll c[N][N];

int main() {
  int n, m;
  cin >> n >> m;
  // 起始条件
  for (int i = 0; i < n; ++i) {
    c[i][0] = 1ll;
  }
  // i的边界
  for (int i = 1; i < n; ++i) {
    // j的边界
    for (int j = 1; j <= i && j < m; ++j) {
      // 状态转移方程
      c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % p;
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << c[i][j] << ' ';
    }
    cout << '\n';
  }
}