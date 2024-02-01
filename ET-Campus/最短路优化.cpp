#include <array>
#include <bitset>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using ll = long long;
const int N = 1e3 + 5;

struct Edge {
  ll x, w;
  bool operator<(const Edge &v) const {
    // w小的优先
    return w == v.w ? x < v.x : w > v.w;
  }
};

vector<Edge> g[N];
array<ll, N> a;
ll n, m;

void dijkstra(int st) {
  a.fill(0x3f3f3f3f3f3f3f3f);
  a[st] = 0;
  bitset<N> vis; // 表示已经拓展过

  priority_queue<Edge> pq;
  pq.push({st, a[st]});
  while (pq.size()) {
    int x = pq.top().x;
    pq.pop();

    // 防止反复入队
    if (vis[x])
      continue;
    vis[x] = 1;

    for (auto &[y, w] : g[x]) {
      if (!vis[y] && a[y] > a[x] + w) {
        a[y] = a[x] + w;
        pq.push({y, a[y]});
      }
    }
  }
}

int main() {
  cin >> n >> m;
  for (ll i = 1; i <= m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    if (u != v)
      g[u].push_back({v, w});
  }
  dijkstra(1);
  // 判断是否能到达
  cout << (a[n] >= 0x3f3f3f3f3f3f3f3f ? -1 : a[n]) << '\n';
}