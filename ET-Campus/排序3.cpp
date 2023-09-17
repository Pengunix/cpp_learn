#include <iostream>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;

int c[N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    c[x]++;
  }
  for (int i = 0; i <= 2e5; ++i) {
    for (int j = 0; j < c[i]; ++i)
      cout << i << ' ';
  }
  cout << '\n';
}
