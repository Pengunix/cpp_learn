#include <algorithm>
#include <iostream>

using namespace std;
using ll = long long;
const int N = 1e5 + 10;

struct Book {
  int a, b, c;
  bool operator<(const Book &u) const {
    if (a == u.a && b == u.b)
      return c > u.c;
    if (a == u.a)
      return b > u.b;
    return a > u.a;
  }
} p[N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> p[i].a >> p[i].b >> p[i].c;

  // 左闭右开区间排序
  sort(p + 1, p + 1 + n);
  // reverse(p+1, p+1+n);

  for (int i = 1; i <= n; ++i) {
    cout << p[i].a << ' ' << p[i].b << ' ' << p[i].c << '\n';
  }
}