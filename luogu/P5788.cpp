// 右边第一个比他大的元素下标 AC
#include <iostream>
#include <stack>
using namespace std;
using ll = long long;
const int N = 3e6 + 5;
int a[N], l[N];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  // 从栈顶开始 元素递增
  stack<int> stk;
  // 先入一个元素 表示遍历过
  stk.push(1);
  // 从第二个元素开始比较
  for (int i = 2; i <= n; ++i) {
    // 当前元素小于等于栈顶元素 直接入栈
    if (a[i] <= a[stk.top()]) {
      stk.push(i);
    }
    // 当前元素若大于栈顶 与每个元素比较 直到栈为空 
    while (!stk.empty() && a[i] > a[stk.top()]) {
      l[stk.top()] = i;
      stk.pop();
    }
    // 将当前元素入栈 供下次比较
    stk.push(i);
  }
  for (int i=1;i<=n;++i) {
    cout << l[i] << ' ';
  }
  
}