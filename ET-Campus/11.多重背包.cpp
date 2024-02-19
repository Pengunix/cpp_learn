#include <iostream>
using namespace std;
using ll = long long;
const int N = 100 + 10;
const ll inf = 4e18, p = 998244353;
ll dp[N];

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ll m, n;
  cin >> m >> n;
  for (int i = 1; i <= n; ++i) {
    ll s, w, v;
    cin >> s >> w >> v;
    while (s--) { // 跑s次01背包
      for (int j = m; j >= v; --j) {
        dp[j] = max(dp[j], dp[j - v] + w);
      }
    }
  }
  cout << dp[m];
}