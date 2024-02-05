#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;

int pre[N], cnt[N];

int root(int x) { return pre[x] = (pre[x] == x ? x : root(pre[x])); }

void merge(int x, int y) { pre[root(x)] = root(y); }

bool isCon(int x, int y) { return root(x) == root(y); }

int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; ++i) {
    pre[i] = i;
  }

  for (int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    merge(u, v);
  }

  for (int i = 1; i <= n; ++i) {
    cnt[root(i)]++;
  }

  vector<int> v;
  for (int i = 1; i <= n; ++i) {
    if (cnt[i])
      v.push_back(cnt[i]);
  }
  sort(begin(v), end(v));
  for (auto &i : v) {
    cout << i << ' ';
  }
}