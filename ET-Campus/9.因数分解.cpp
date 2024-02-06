#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
const ll inf = 4e18, p = 998244353;


int main() {
  ll n;
  cin >> n;
  vector<ll> v;

  for (ll i=1;i*i<=n;++i) {
    if (n % i)
      continue;

    v.push_back(i);
    if (i != n/i) v.push_back(n/i);
  }
  sort(v.begin(), v.end());
  for (auto &i : v) {
    cout << i << ' ';
  }
  
}