// 关闭O2就能过
#include <cstring>
#include <iostream>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
const ll inf = 4e18, p = 998244353;
int n, a, b;
int k[210];
int ans[210];

int dx[] = {1, -1};

void dfs(int st, int sum) {
  ans[st] = sum;
  if (st == b) {
    return;
  }
  for (int i=0;i<2;++i) {
    int flor = st + dx[i]*k[st];
    if (flor > 0 && flor <=n && sum + 1 < ans[flor] || ans[flor] == -1) dfs(flor, sum+1);
  }
  
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n>> a >> b;
  for (int i=1;i<=n;++i) {
    cin >> k[i]; 
  }
  memset(ans, -1, sizeof ans);
  dfs(a, 0);
  cout << ans[b];
}