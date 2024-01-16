#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const int N = 2000 + 50;

ll a[300009];
vector<int> X;
struct Q {
  int a,b;
} add[N], que[N];

int getidx(ll x) {
  // 找出数组第一个大于等于的元素的迭代器。
  return lower_bound(X.begin(), X.end(), x) - X.begin() +1;
}

int main() {
  int n, q;
  cin >> n >> q;
  for (int i=1;i<=n;++i) {
    int x, w;
    cin >> x >> w;
    X.push_back(x);
    add[i] = {x, w};
  }

  for (int i=1;i<=q;++i) {
    int l, r;
    cin >> l >> r;
    X.push_back(l), X.push_back(r);
    que[i] = {l, r};
  }
  sort(X.begin(), X.end());
  X.erase(unique(X.begin(),X.end()), X.end());

  for (int i=1;i<=n;++i) {
    // c++17 结构化绑定，蓝桥杯不能用
    auto [x, w] = Q{getidx(add[i].a), add[i].b};
    a[x] += w;
  }
  for (int i=1;i<=X.size();++i) {
    a[i] += a[i-1];
  }
  for (int i=1;i<=q;++i) {
    auto [l, r] = Q{getidx(que[i].a), getidx(que[i].b)};
    cout << a[r] - a[l-1] << '\n';
  }
}