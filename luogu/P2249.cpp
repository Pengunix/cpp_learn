// 二分

#include <algorithm>
#include <iostream>
using namespace std;
const int N = 1e6 + 10;
const int M = 1e9;

int a[N], t;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i)
    cin >> a[i];

  for (int i = 1; i <= m; ++i) {
    cin >> t;
    int *p = lower_bound(a + 1, a + n + 1, t);
  }
}