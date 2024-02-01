#include <iostream>
using namespace std;
using ll = long long;

const int N = 1e3 + 10;

ll a[N][N], p[N][N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n, m, q;
  cin >> n >> m >> q;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      cin >> a[i][j];

  // 计算prefix
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      p[i][j] = p[i - 1][j] + p[i][j - 1] - p[i-1][j-1] + a[i][j];

  while (q--) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ll ans = p[x2][y2] - p[x2][y1-1] - p[x1-1][y2] + p[x1-1][y1-1];
    cout << ans << '\n';
  }
}