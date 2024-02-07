#include <iostream>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
ll n, m, squ = 0, rec = 0;
void test1() {
  cin >> n >> m;
  for (ll x = 0; x <= n; ++x) {
    for (ll y = 0; y <= m; ++y) {
      ll tmp = min(x, y) + min(y, n - x) + min(n - x, m - y) + min(m - y, x);
      squ += tmp;
      rec += n*m - tmp;
    }
  }
  cout << squ/4 << ' ';
}

void test2() {
  cin >> n >> m;
  for (ll x = 0; x <= n; ++x) {
    for (ll y = 0; y <= m; ++y) {
      ll tmp = min(x, y);
      squ += tmp;
      rec += x*y - tmp;
    }
  }
}
int main() {
  // test1();

}