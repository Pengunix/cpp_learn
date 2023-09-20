#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;

int w[N], v[N], p[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n,m,s;
  cin >> n >> m >> s;
  for (int i = 1; i <= n; ++i)
    cin >> w[i] >> v[i];
  int W = 4;
  for (int i = 1; i <= n; ++i)
    p[i] = p[i-1] + w[i] >= W ? w[i] * v[i] : 0;

  int l,r,y,min=0,tmp;
  while (m--) {
    cin >> l >> r;
    y = p[r] - p[l-1];

    cout << y << " ";
    
    tmp = abs(s-y);
    if (tmp < min) {
      min = tmp;
    }
  }
  cout << tmp << '\n';

}