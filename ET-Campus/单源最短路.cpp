#include <bitset>
#include <iostream>
#include <vector>
#include <array>
using namespace std;
using ll = long long;
const int N = 1e3 + 5;
// O(n^2)
struct Edge {
  int x, w;
};

vector<Edge> g[N];
array<ll, N> d;
ll n, m;

void dijkstra(int st) {
  d.fill(0x3f);
  d[st] = 0;
  bitset<N> vis; // 表示已经拓展过
  for (int i=1;i<=n;++i) {
    // 找出最小点，距离原点最近
    int u = 1;
    for (int j = 1; j <= n; ++j) {
      if (vis[u] || (!vis[j] && d[j] < d[u]))
        u = j;
    }
    vis[u] = 1; // 表示u已经拓展过
    // d[u]已是最优的
    for (auto &[v, w] : g[u]) {
      if (!vis[v] && d[v] > d[u] + w)
        d[v] = d[u] + w;
    }
  }
}

int main() {
  cin >> n >> m;
  for (ll i=1;i<=m;++i) {
    int u, v, w;
    cin >> u >> v >> w;
    if (u !=v) g[u].push_back({v, w});
  }
  dijkstra(1);
  // 判断是否能到达
  cout << (d[n]>= 0x3f3f3f3f3f3f3f3f ? -1 : d[n]) << '\n';
  
}