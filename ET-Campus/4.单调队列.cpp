// 滑动窗口最大值 最小值
#include <deque>
#include <iostream>
using namespace std;
using ll = long long;
const int N = 1e6 + 10;

int a[N];

int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  deque<int> dq;
  // 求最小
  for (int i = 1; i <= n; ++i) {
    // 以i为右端点，大小为k的区间，[i-k+1, i]
    while (!dq.empty() && dq.front() <= i - k)
      dq.pop_front();
    while (!dq.empty() && a[dq.back()] >= a[i])
      dq.pop_back();

    dq.push_back(i);

    if (i >= k)
      cout << a[dq.front()] << ' ';
  }
  cout << '\n';
  dq.clear();
  // dq= deque<int>();
  for (int i = 1; i <= n; ++i) {
    // 以i为右端点，大小为k的区间，[i-k+1, i]
    while (!dq.empty() && dq.front() <= i - k)
      dq.pop_front();
    while (!dq.empty() && a[dq.back()] <= a[i])
      dq.pop_back();

    dq.push_back(i);

    if (i >= k)
      cout << a[dq.front()] << ' ';
  }
}