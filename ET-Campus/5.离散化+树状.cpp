// 求逆序对个数，权值数组（桶）
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
const ll inf = 4e18, p = 998244353;
ll a[N], t[N];
vector<int> X;

int bin(int x) {
  // +1去除0
  return lower_bound(X.begin(), X.end(), x) - X.begin() +1;
}
int lowbit(int x) {
  return x&-x;
}

void update(int k, int x) {
  for (int i = k; i <= X.size(); i += lowbit(i)) {
    t[i] += x;
  }
}
int getsum(int k) {
  int res = 0;
  for (int i = k; i > 0; i -= lowbit(i)) {
    res += t[i];
  }
  return res;
}
int main() {
  int n;
  cin >> n;
  for (int i=1;i<=n;++i) {
    cin >> a[i];
    X.push_back(a[i]);
  }

  sort(X.begin(), X.end());
  X.erase(unique(X.begin(), X.end()), X.end());
  ll ans = 0;
  for (int i=1;i<=n;++i) {
    ans += getsum(X.size()) - getsum(bin(a[i]));
    update(bin(a[i]), 1);
  }
  cout << ans;
  
}