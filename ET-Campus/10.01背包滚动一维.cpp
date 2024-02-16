#include <iostream>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
const ll inf = 4e18, p = 998244353;
ll T, M;
ll dp[1010];
ll t[105], v[1010];

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  while (cin >> T >> M) {
    if (T == 0 &&M == 0)
      break;
    for (int i=0;i<=T;++i) {
      dp[i] = 0;
    }
    for (int i=1;i<=M;++i) {
      cin >> t[i] >> v[i];
    }
    for (int i = 1; i <= M; ++i) {
      for (int j=T;j>=t[i];--j) {
        dp[j] = max(dp[j], dp[j-t[i]] + v[i]);
      }
    }
    cout << dp[T] << '\n';
  }
}