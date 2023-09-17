#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// 1.确定N的大小，不要用define
const int N = 1e5 + 10;

// 2.开数组，全局数组自动初始化为0
int a[N], prefix[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  // 里面开用的是栈空间(2m, 4m)
  // int b[N]; 尽量用全局
  // 3.输入
  int n;
  cin >> n;

  // for (int i = 1; i <= n; ++i) {
  //   cin >> a[i];
  //   prefix[i] = prefix[i - 1] + a[i];
  // }
  // 分开做会快点
  for (int i = 1; i <= n; ++i)
    cin >> a[i];
  for (int i = 1; i <= n; ++i)
    prefix[i] = prefix[i - 1] + a[i];
}