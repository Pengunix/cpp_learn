#include <algorithm>
#include <iostream>
using namespace std;
const int N = 1e5 + 7;

int t[N], a[N];

int main() {
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++)
    cin >> a[i], t[i] = a[i];
  sort(t + 1, t + n + 1);
  int m;
  m = unique(t + 1, t + n + 1) - t - 1;
  for (int i = 1; i <= n; i++)
    a[i] = lower_bound(t + 1, t + m + 1, a[i]) - t;
}