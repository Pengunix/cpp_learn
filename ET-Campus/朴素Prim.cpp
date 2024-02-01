#include <bitset>
#include <cstring>
#include <iostream>
using namespace std;
using ll = long long;
const int N = 1e3 + 10;
const ll inf = 4e18, p = 998244353;

int a[N][N], d[N];
bitset<N> intree;
int main() {
  int n, m;
  cin >> n >> m;
  memset(a, 0x3f, sizeof a);
  memset(d, 0x3f, sizeof d);
  for (int i = 1; i <= n; ++i) {
    a[i][i] = 0;
  }

  for (int i = 1; i <= m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    // 排除无向图出现重边
    a[u][v] = min(a[u][v], w);
    a[v][u] = min(a[v][u], w);
  }

  ll ans = 0;

  for (int i = 1; i <= n; ++i) {
    int u = 1; // u就是距离intree点最近的点
    for (int j = 1; j <= n; ++j) {
      if (intree[u] || (!intree[j] && d[j] < d[u]))
        u = j;
    }
    if (d[u] < 0x3f)
      ans += d[u];
    intree[u] = 1;
    d[u] = 0;
    for (int j = 1; j <= n; ++j) {
      if (intree[j])
        continue;
      d[j] = min(d[j], a[u][j]);
    }
  }
  cout << ans;
}