// 右边第一个比他小的元素
#include <iostream>
#include <stack>
using namespace std;
using ll = long long;
const int N = 1e5 + 10;
int a[N], l[N];

int main() {
  int n;cin >> n;
  for (int i=1;i<=n;++i) {
    cin >> a[i];
  }
  stack<int> stk;

  for (int i=1;i<=n;++i) {
    while (!stk.empty() && stk.top() >= a[i])
      stk.pop();
    if (stk.empty())
      l[i] = -1;
    else
      l[i] = stk.top();
    stk.push(a[i]);
  }

  for (int i=1;i<=n;++i) {
    cout << l[i] << ' ';
  }
}
