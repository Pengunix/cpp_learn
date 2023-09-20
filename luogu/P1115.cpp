// 最长子段和 三种做法 待补充
#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;

ERR


int a[N], p[N];
int ans;

int main() {

  int n; cin >> n;
  for (int i=1;i<=n;++i)
    cin >> a[i];

  for (int i=1;i<=n;++i)
    p[i] = p[i-1] + a[i];

  int cur_min = 0;
  int ans = p[1];
  int tmp;

  for (int i = 1; i <= n; ++i) {
    tmp = p[i] - cur_min;
    if (tmp > ans)
      ans = tmp;
    cur_min = min<int>(cur_min,p[i]);
  }
  cout << ans << '\n';
  
  
}