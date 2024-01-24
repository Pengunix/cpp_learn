#include <iostream>
using namespace std;
using ll = long long;
const int N = 1010;

int a[N];
int dp[N][10010];

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  for (int i = 0; i <= n; i++) {
    dp[i][0] = 1;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      dp[i][j] += dp[i - 1][j];
      if (j >= a[i]) {
        dp[i][j] += dp[i - 1][j - a[i]];
      }
    }
  }
  cout << dp[n][m];
  return 0;
}