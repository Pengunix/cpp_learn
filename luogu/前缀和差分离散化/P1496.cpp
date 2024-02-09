// 洛谷用c++11提交能过 c++14不过
#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
const ll inf = 4e18, p = 998244353;

ll a[N], b[N];

void solve() {
  int n;
  cin >> n;
  ll ans;

  for (int i = 1; i <= n; ++i) {
    cin >> a[i] >> b[i];
  }
  sort(a + 1, a + n + 1);
  sort(b + 1, b + 1 + n);

  for (int i = 1; i <= n; ++i) {
    ans += b[i] - a[i];
    if (i < n) {
      if (b[i] > a[i + 1]) {
        ans -= b[i]-a[i+1];
      }
    }
  }
  cout << ans;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t = 1;
  while (t--)
    solve();
}