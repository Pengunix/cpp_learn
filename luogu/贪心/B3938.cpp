#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const int N = 1e6 + 10;
const ll inf = 4e18, p = 998244353;
int a[N];
vector<int> b;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int T;
  cin >> T;
  ll ans = 0;
  while (T--) {
    ans = 0;
    b.clear();
    int n, t, m;
    cin >> n >> t >> m;
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
    }
    for (int i = 1; i <= m; ++i) {
      int x;
      cin >> x;
      a[x] -= 2;
    }
    for (int i = 1; i <= n; ++i) {
      if (a[i] > 0)
        ans++;
      else
        b.push_back(a[i]);
    }

    sort(b.begin(), b.end(), greater<int>());
    for (auto &i : b) {
      t -= (1 - i);
      if (t >= 0)
        ans++;
      else
        break;
    }
    cout << ans << '\n';
  }
}