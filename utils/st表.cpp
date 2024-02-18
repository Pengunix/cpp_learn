#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;
const int N = 1e5 + 10;
const ll inf = 4e18, p = 998244353;

vector<vector<int>> st; // 表示左端点为i长度为2^j的区间，也就是[i, i+2^j-1]
int a[N];

int query(int l, int r) {
  int j = static_cast<int>(log2(r - l + 1));
  return max(st[l][j], st[r-(1<<j)+1][j]);
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, q;
  cin >> n >> q;
  for (int i=0;i<n;++i) {
    cin >> a[i];
  }
  st = vector<vector<int>>(n, vector<int>(static_cast<int>(log2(n))+5, 0));
  for(int i=0;i<n;i++) st[i][0] = a[i];
  for (int j=1; j<=log2(n); j++) {
    for (int i=0; i+(1<<j)-1 < n; i++) {
      st[i][j] = max(st[i][j-1], st[i+(1<<(j-1))][j-1]);
    }
  }
  int l, r;
  // while (cin >> l >> r) {
  //   cout << query(l, r) << endl;
  // }
  while (q--) {
    cin >> l >> r;
    cout << query(l-1, r-1) << '\n';
  }
}