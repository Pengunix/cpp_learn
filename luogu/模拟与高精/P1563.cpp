// 评测通过
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const int N = 1e5 + 10;
// 可以试试结构体数组，老是忘用
vector<pair<int, string>> v(N);
int n,m,x,y;

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> v[i].first >> v[i].second;
  }
  int now = 0;
  // 移动指针是有代价的，计算索引效率更高
  for (int i = 1; i <= m; i++) {
    cin >> x >> y;
    if (v[now].first == 0 && x == 0)
      now = (now + n - y) % n;
    else if (v[now].first == 0 && x == 1)
      now = (now + y) % n;
    else if (v[now].first == 1 && x == 0)
      now = (now + y) % n;
    else if (v[now].first == 1 &&x == 1)
      now=  (now + n - y) % n;
  }
  cout << v[now].second << endl;
  return 0;
}