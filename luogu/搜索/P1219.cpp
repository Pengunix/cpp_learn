#include <iostream>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
const ll inf = 4e18, p = 998244353;
// 行，列，左上右下，左下右上
int a[14], v[14], v1[28], v2[28];
int n, cnt;
void dfs(int r) {
  if (r == n + 1) {
    if (cnt <= 2) { // 题目只要前三个解
      for (int i = 1; i <= n; ++i) {
        // 打印行的哪个列满足要求
        cout << a[i] << " ";
      }
      cout << '\n';
    }
    cnt++;
    return;
  }
  for (int i = 1; i <= n; ++i) {
    if (!v[i] && !v1[r + i] && !v2[r - i + n]) {
      // cout << i << " \n"[i==n];
      a[r] = i;
      v[i] = 1;
      v1[r + i] = 1;
      v2[r - i + n] = 1;
      dfs(r + 1);
      v[i] = 0;
      v1[r + i] = 0;
      v2[r - i + n] = 0;
    }
  }
}

int main() {
  cin >> n;
  dfs(1);
  cout << cnt;
}