#include <iostream>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
const ll inf = 4e18, p = 998244353;

ll a[N], t[N];
int lowbit(int x) {
  return x&-x;
}
int n, q;
// O(logn)
void update(int k, ll x) {
  for(int i= k;i<=n;i+=lowbit(i)) t[i] += x;
}

ll getsum(int k) {
  ll res = 0;
  for(int i=k;i>0;i-=lowbit(i)) res += t[i];
  return res;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  for (int i = 1; i <= n; ++i) {
    // 全零的树状数组，给第i个加上a[i]
    update(i, a[i]);
  }
  // O(q) O(n)
  while (q--) {
    int op;
    cin >> op;
    if (op == 1) {
      ll k, v;
      cin >> k >> v;
      update(k, v);
    } else {
      ll l, r;
      cin >> l >> r;
      cout << getsum(r) - getsum(l-1) << '\n';
    }
  }
}