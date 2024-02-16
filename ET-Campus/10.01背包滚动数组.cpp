#include <iostream>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
const ll inf = 4e18, p = 998244353;
ll T, M;
ll dp[2][1010];
ll t[105], v[1010];

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  while (cin >> T >> M) {
    if (T == 0 && M == 0)
      break;
    // 初始化可省略 多组样例尽量写上 滚动数组必须加
    for (int i = 0; i <= T; ++i) {
      dp[0][i] = 0;
    }

    for (int i = 1; i <= M; ++i) {
      cin >> t[i] >> v[i];
    }
    // 1<=i<=m 0<=j<=t
    // for (int i = 1; i <= M; ++i) {
    //   int y = i & 1; // y表示当前行
    //   for (int j=0;j<=T;++j) {
    //     // 最大价值转移
    //     if (j>=t[i]) dp[y][j] = max(dp[y^1][j], dp[y^1][j-t[i]] + v[i]);
    //     else dp[y][j] = dp[y^1][j];
    //   }
    // }
    for (int i = 1; i <= M; ++i) {
      int y = i & 1; // y表示当前行
      // 先进行不选的转移
      for (int j = 0; j <= T; ++j)
        dp[y][j] = dp[y ^ 1][j];
      for (int j = t[i]; j <= T; ++j) {
        // 最大价值转移
        dp[y][j] = max(dp[y][j], dp[y ^ 1][j - t[i]] + v[i]);
      }
    }
    cout << dp[M & 1][T] << '\n';
  }
}