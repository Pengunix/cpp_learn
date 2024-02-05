#include <bitset>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using ll = long long;
const int N = 5e5 + 10;
const ll inf = 4e18, p = 998244353;

int n, m, k;
struct edge {
  int x;
  ll w;
  bool operator<(const edge &v) const {
    return w > v.w;
  }
};
vector<edge> g[N];
ll d[N];
bitset<N> vis;

priority_queue<edge> pq;
void dijkstra(int st) {
  memset(d, 0x3f, sizeof(d));
  d[st] = 0;
  pq.push({st, d[st]});

  while (pq.size()) {
    int x = pq.top().x;
    pq.pop();

    if (vis[x])
      continue;
    vis[x] = 1;

    for (edge &i : g[x]) {
      if (!vis[i.x] && d[i.x] > d[x] + i.w) {
        d[i.x] = d[x] + i.w;
        pq.push({i.x, d[i.x]});
      }
    }
  }
}


int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m >> k;
  int s, t;
  cin >> s >> t;

  int a, b, c;
  for (int i = 0; i < m; ++i) {
    cin >> a >> b >> c;
    g[a].push_back({b, c});
    g[b].push_back({a, c});
    for (int j = 1; j <= k; ++j) {
      g[a+(j-1) * n].push_back({b+j*n, 0});
      g[b+(j-1)* n].push_back({a+j*n, 0});

      g[a + j * n].push_back({b + j * n, c});
      g[b+j*n].push_back({a+j*n, c});
    }
  }
  for (int i = 1; i <= k; ++i) {
    g[t+(i-1)*n].push_back({t+i*n, 0});
  }
  dijkstra(s);
  cout << d[t + k * n];

}