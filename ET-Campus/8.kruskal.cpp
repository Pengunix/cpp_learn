#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const int N = 1e5 + 10;
const ll inf = 4e18, p = 998244353;
ll d[N];
int pre[N];
int root(int x) {
  // 求根+路径压缩
  return pre[x] = (pre[x] == x ? x : root(pre[x]));
}

struct Edge {
  ll u, v, w;
  bool operator<(const Edge &m) const {
    return w == m.w ? (u==m.w?v<m.v:u<m.w) : w < m.w;
    // return w<m.w;
  }
};

int main() {
  int n, m;
  cin >> n >> m;
  memset(d, 0x3f, sizeof d);

  vector<Edge> es;
  for (int i=1;i<=m;++i) {
    ll u, v, w;cin >> u>> v>> w;
    es.push_back({u, v, w});
  }

  sort(es.begin(), es.end());
  ll ans = 0;
  for (int i=1;i<=n;++i) {
    pre[i] = i;
  }

  for (auto &[u, v, w] : es) {
    if (root(u) == root(v))
      continue;
    ans += w;
    pre[root(u)] = root(v);
  }
  for (int i=1;i<n;++i) {
    if (root(i) != root(i+1)) ans = -1;
  }
  cout << ans;
}