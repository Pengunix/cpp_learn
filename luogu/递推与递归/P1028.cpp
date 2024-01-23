// AC
#include <iostream>
#include <array>
using namespace std;
using ll = long long;

int n;
array<int, 101> f;

int sol(int x) {
  int ans = 1;
  if (f[x] != -1)
    return f[x];
  for (int i = 1; i <= x/2; i++)
    ans += sol(i);
  return f[x] = ans;
}

int main() {
  cin >> n;
  f.fill(-1);
  f[1] = 1;
  cout << sol(n) << endl;
  return 0;
}