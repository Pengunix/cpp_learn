#include <iostream>
using namespace std;
using ll = long long;
const int N = 1e9 + 10;
const ll inf = 4e18, p = 1e9 + 7;

ll fac[N];

void init(int n) {
  fac[0] = 1;
  for (int i = 1; i <= n; ++i)
    fac[i] = fac[i - 1] * i % p;
}

ll qpow(ll a, ll b) {
  ll res = 1;
  while (b) {
    if (b & 1)
      res = res * a % p;
    a = a * a % p;
    b >>= 1;
  }
  return res;
}

ll inv(ll x) { return qpow(x, p - 2); }

ll C(ll n, ll m) {
  if (n < 0 || m < 0 || n < m) {
    return 0;
  }
  return fac[n] * inv(fac[n - m] * fac[m] % p) % p;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  init(1e7);
  int q;
  cin >> q;
  ll a, b;
  while (q--) {
    cin >> a >> b;
    cout << C(a, b) << '\n';
  }
}