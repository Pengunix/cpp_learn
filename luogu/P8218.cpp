// 求区间和
#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;
const int N = 1e5 + 10;

int a[N], p[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  for (int i = 1; i <= n; ++i)
    cin >> a[i];
  for (int i = 1; i <= n; ++i)
    p[i] = p[i - 1] + a[i];

  int m;
  cin >> m;

  while (m--) {
    int l, r;
    cin >> l >> r;
    cout << p[r] - p[l - 1] << '\n';
  }
}