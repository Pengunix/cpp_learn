#include <cstring>
#include <iostream>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
 // ?
int a[N], c[N];

void solve() {
  int n;
  cin >> n;

  for (int i = 1; i <= n; ++i) cin >> a[i];

  for (int i= 1;i<=n;++i) c[a[i]] = 0;

  ll ans = 0;
  for (int i = 1, j = 0; i <= n; ++i) {
    while (j < n && !c[a[j + 1]])
      c[a[++j]]++;
    ans = max<ll>(ans, j - i + 1ll);
    c[a[i]] --;
  }


}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int _;
  cin >> _;
  while (_--) {
    solve();
  }

}