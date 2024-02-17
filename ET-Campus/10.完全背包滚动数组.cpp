#include <iostream>
using namespace std;
using ll = long long;
const int N = 500 + 10;
const ll inf = 4e18, p = 998244353;
ll n, m;
ll dp[2][100010];
ll w[N], v[N];

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> m >> n;

  for (int i = 1; i <= n; ++i) {
    cin >> w[i] >> v[i];
  }

  for (int i = 1; i <= n; ++i) {
    int y = i & 1;
    for (int j = 0; j <= m; ++j) {
      if (j>=v[i])dp[y][j] = max(dp[y^1][j], dp[y][j - v[i]] + w[i]);
      else dp[y][j] = dp[y^1][j];
    }
  }
  cout << dp[n&1][m];

}