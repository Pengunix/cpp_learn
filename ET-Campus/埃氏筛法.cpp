#include <bitset>
#include <iostream>
using namespace std;
using ll = long long;
const int N = 2e6 + 10;

bitset<N> vis;

int main() {
  int n;
  cin >> n;
  vis[0] = vis[1] = 1;
  for (ll i = 2ll; i <= n; ++i) {
    if (!vis[i])
      for (ll j = i * i; j <= n; j += i)
        vis[j] = 1;
  }
  for (ll i = 1; i <= n; ++i)
    if (!vis[i])
      cout << i << ' ';
}