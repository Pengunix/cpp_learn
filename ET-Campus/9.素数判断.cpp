#include <iostream>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
const ll inf = 4e18, p = 998244353;

bool isprime(int x) {
  if (x<2) return false;
  for (int i = 2; i * i < x; ++i) {
    if (x%i==0) return false;
  }
  return true;
}

int main() {
  int n;
  cin >> n;
  cout << isprime(n);
  
}