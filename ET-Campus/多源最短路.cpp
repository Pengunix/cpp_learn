#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const int N = 300;
const ll inf = 4e18, p = 998244353;

ll d[N][N], n, m, q;

int main() {
  memset(d, 0x3f, sizeof d);
  cin >> n >> m >> q;
  for (int i=1;i<=m;++i) {
    ll u, v, w;
    cin >> u >> v >> w;
    d[u][v] = min(d[u][v], w);
  }
  // 排除自环
  for (int i=1;i<=n;++i) {
    d[i][i]=0;
  }
  

  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
      }
    }
  }

  while (q--) {
    int u, v;
    cin >> u >> v;
    cout << (d[u][v] >= inf ? -1 : d[u][v]) << '\n';
  }
  
}