#include <iostream>
#include <bitset>
using namespace std;
using ll = long long;
const int N = 15;

int a[N], n;
bitset<N> vis;
// 也能用next_permutation做
void dfs(int dep) { // dep当前深度
  // 出口
  if (dep == n + 1) {
    for (int i=1;i<=n;++i) {
      cout << a[i] << " \n"[i==n];
    }
      return;
  }
  for (int i=1;i<=n;++i) {
    if (vis[i])
      continue;
    vis[i] = 1;
    a[dep] = i;
    dfs(dep + 1);

    a[dep] = 0;
    vis[i] = 0;
  }
  
}

int main() {
  cin >> n;
  dfs(1);
}