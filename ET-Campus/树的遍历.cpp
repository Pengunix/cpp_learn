#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using ll = long long;
const int N = 60;
int fa[N];
vector<int> g[N];

void dfs(int x) {
  cout << x << ' ';
  for (auto &y : g[x]) {
    dfs(y);
  }
}

void bfs(int x) {
  queue<int> q;
  q.push(x);
  while (q.size()) {
    int x = q.front();
    q.pop();
    cout << x << ' ';
    for (auto &y : g[x]) {
      q.push(y);
    }
  }
}

int main() {
  int n;cin >> n;
  for (int i=2;i<=n;++i) {
    cin >> fa[i];
  }

  for (int i=2;i<=n;++i) {
    g[fa[i]].push_back(i);
  }
  for (int i=1;i<=n;++i) {
    sort(g[i].begin(), g[i].end());
  }
  
  dfs(1);
  cout << '\n';
  bfs(1);
  
}