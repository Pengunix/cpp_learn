#include <iostream>
#include <stack>
using namespace std;

// stack : First in Last out FILO 先进后出
// 不能遍历 只有栈顶的元素才能被访问

int main() {
  stack<int>  stk;
  stk.push(1);
  stk.push(2);

  cout << (bool)stk.empty() << endl;
  cout << stk.size() << endl;

  cout << stk.top() << endl;
  stk.pop();

  cout << stk.top() << endl;
}
