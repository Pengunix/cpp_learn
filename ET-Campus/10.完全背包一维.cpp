#include <iostream>
using namespace std;
using ll = long long;
const int N = 500 + 10;
const ll inf = 4e18, p = 998244353;
ll n, m;
ll dp[100010];
ll w[N], v[N];

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> m >> n;

  for (int i = 1; i <= n; ++i) {
    cin >> w[i] >> v[i];
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = v[i]; j <= m; ++j) {
      dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
    }
  }
  cout << dp[m];

}