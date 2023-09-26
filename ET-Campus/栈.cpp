#include <iostream>
#include <stack>
using namespace std;
using ll = long long;

const int N = 1e5 + 9;

int a[N], pos;

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> a[i];

  stack<int> s;
  pos = 1;
  for (int i = 1; i <= n; ++i) {
    while (pos <= n && (s.empty() || s.top() != i))
      s.push(a[pos + ]);
    if (s.top() == i)
      s.pop();
    else {
      cout << "NO" << '\n';
      return 0;
    }
  }
  cout << "YES" << '\n';
}