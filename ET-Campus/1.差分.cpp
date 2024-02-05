#include <iostream>
using namespace std;
using ll = long long;

const int N = 1e5 + 10;
ll a[N], diff[N], prefix[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  for (int i = 1; i <= n; ++i)
    cin >> a[i];
  for (int i = 1; i <= n; ++i)
    diff[i] = a[i] - a[i - 1]; // 求差分数组

  int m;
  cin >> m;
  while (m--) {
    ll l, r, x;
    cin >> l >> r >> x;
    diff[l] += x, diff[r + 1] -= x; // 区间修改
  }

  for (int i = 1; i <= n; ++i)
    a[i] = a[i - 1] + diff[i]; // 差分还原

  for (int i = 1; i <= n; ++i)
    prefix[i] = prefix[i - 1] + a[i];

  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << prefix[r] - prefix[l - 1] << '\n';
  }
}