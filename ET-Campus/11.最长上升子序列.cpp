#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
const ll inf = 4e18, p = 998244353;
ll a[N], dp[N];

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  for (int i=1;i<=n;++i) {
    cin >> a[i];
  }

  for (int i=1;i<=n;++i) {
    dp[i] = 1;
    for (int j=1; j<i; ++j) {
      if (a[j]<=a[i]) dp[i] = max(dp[i], dp[j]+1);
    }
  }

  ll ans = *max_element(dp+1, dp+1+n);
  cout << ans;
}