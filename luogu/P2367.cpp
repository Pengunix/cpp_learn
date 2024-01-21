// 差分 语文成绩 AC
#include <iostream>
using namespace std;
using ll = long long;

const int N = 5e6 + 10;
ll a[N], diff[N], prefix[N];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, p;
  cin >> n >> p;

  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  for (int i = 1; i <= n; ++i) {
    diff[i] = a[i] - a[i-1];
  }

  int x,y,z;
  while (p--) {
    cin >> x >> y >> z;
    diff[x] += z;
    diff[y + 1] -= z;
  }
  int min = 2147483647;
  for (int i = 1; i <= n; ++i) {
    a[i] = a[i-1] + diff[i];
    if (a[i] < min) {
      min = a[i];
    }
  }
  cout << min << '\n';

}