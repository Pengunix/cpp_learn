#include <bitset>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
const ll inf = 4e18, p = 998244353;

struct Edge {
  ll x, w;
  bool operator<(const Edge &u) const {
    return w ==u.w?x<u.x:w>u.w;
  }
};
vector<Edge> g[N];
ll d[N];
bitset<N> intree;

int main() {
  int n, m;
  cin >> n >> m;
  memset(d, 0x3f, sizeof d);

  for (int i = 1; i <= m; ++i) {
    ll u, v, w;
    cin >> u >> v >> w;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }
  ll ans = 0;
  priority_queue<Edge> pq;

  pq.push({1, 0});
  d[1] = 0; 
  while (pq.size()) {
    // auto [x, w] = pq.top();
    int x = pq.top().x;
    pq.pop();
    if (intree[x])
      continue;
    intree[x] = 1;
    // ans += w;
    ans += d[x];
    d[x] = 0;

    for (auto &[y, w] : g[x]) {
      if (!intree[y] && w < d[y]) {
        d[y] = w;
        pq.push({y, w});
      }
    }
  }

  for (int i=1;i<=n;++i) {
    if (!intree[i]) ans = -1;
  }
  
  cout << ans << '\n';
}