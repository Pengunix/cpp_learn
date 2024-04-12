// AC 给定n个整数，求它们两两相乘再相加的和
#include <iostream>
using namespace std;
using ll = long long;
const int N = 2 * 1e5 + 10;
ll a[N], sum[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> a[i];
  for (int i = 1; i <= n; ++i)
    sum[i] = sum[i - 1] + a[i];

  ll ans = 0;
  for (int i = 1; i <= n - 1; i++)
    ans += a[i] * (sum[n] - sum[i]);
  cout << ans << '\n';
}