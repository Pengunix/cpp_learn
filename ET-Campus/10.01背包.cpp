#include <iostream>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
const ll inf = 4e18, p = 998244353;
ll T, M;
ll dp[105][1010];
ll t[105], v[1010];

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  while (cin >> T >> M) {
    if (T == 0 &&M == 0)
      break;
    // 初始化可省略 多组样例尽量写上
    for (int i=0;i<=T;++i) {
      dp[0][i] = 0;
    }

    for (int i=1;i<=M;++i) {
      cin >> t[i] >> v[i];
    }
    // 1<=i<=m 0<=j<=t
    for (int i = 1; i <= M; ++i) {
      for (int j=0;j<=T;++j) {
        // 最大价值转移
        if (j>=t[i]) dp[i][j] = max(dp[i-1][j], dp[i-1][j-t[i]] + v[i]);
        else dp[i][j] = dp[i-1][j];
      }
    }
    cout << dp[M][T] << '\n';
  }
}