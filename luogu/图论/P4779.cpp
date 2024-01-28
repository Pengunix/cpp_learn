#include <bitset>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include <array>
using namespace std;
using ll = long long;
const int N = 1e5 + 5;

struct Edge {
  ll x, w;
  bool operator<(const Edge &v) const {
    // w小的优先
    return w == v.w ? x < v.x: w > v.w;
  }
};

vector<Edge> g[N];
array<ll, N> d;
ll n, m;

void dijkstra(int st) {
  d.fill(0x3f3f3f3f3f3f3f3f);
  d[st] = 0;
  bitset<N> vis; // 表示已经拓展过

  priority_queue<Edge> pq;
  pq.push({st, d[st]});
  while (pq.size()) {
    int x = pq.top().x;pq.pop();

    // 防止反复入队
    if (vis[x])
      continue;
    vis[x] = 1;

    for (auto &[y, w] : g[x]) {
      if (!vis[y] && d[y] > d[x] + w) {
        d[y] = d[x] + w;
        pq.push({y, d[y]});
      }
    }
  }

}

int main() {
  int s;
  set<int> se;
  cin >> n >> m >> s;
  for (ll i=1;i<=m;++i) {
    int u, v, w;
    cin >> u >> v >> w;
    se.insert(v);
    se.insert(u);
    if (u != v) {
      g[u].push_back({v, w});
      
    }
  }
  dijkstra(s);
  // 判断是否能到达
  // cout << (d[n]>= 0x3f3f3f3f3f3f3f3f ? -1 : d[n]) << '\n';
  for (auto &i : se) {
    cout << d[i] << ' ';
  }
}