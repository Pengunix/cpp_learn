#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const int N = 2000+ 10;
const ll inf = 4e18, p = 998244353;
ll dp[N];

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ll m, n;
  cin >> m >> n;
  for (int i = 1; i <= n; ++i) {
    ll s, w, v;
    cin >> s >> w >> v;
    vector<int> vv;
    int x = 1;
    while (s >= x) {
      vv.push_back(x);
      s -= x;
      x<<=1;
    }
    if (s != 0) vv.push_back(s);
    for (auto &k: vv) {
      for (int j = m; j >=k* v; --j) {
        dp[j] = max(dp[j], dp[j - k*v] + k*w);
      }
    }
  }
  cout << dp[m];
}