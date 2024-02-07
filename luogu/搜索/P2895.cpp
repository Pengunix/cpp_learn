#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
using ll = long long;
const int N = 1010;
const ll inf = 4e18, p = 998244353;

int dx[] = {1, -1, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0};

struct node {
  int x, y, t, s, vis;
} ma[N][N];

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int m;
  cin >> m;
  memset(ma, -1, sizeof ma);
  int x, y, t;
  for (int i = 0; i < 1000; ++i) {
    for (int j = 0; j < 1000; ++j) {
      ma[i][j].x = i;
      ma[i][j].y = j;
    }
  }

  for (int i = 1; i <= m; ++i) {
    cin >> x >> y >> t;
    for (int j = 0; j <= 4; ++j) {
      int nx = x + dx[j];
      int ny = y + dy[j];
      if (nx < 0 || ny < 0)
        continue;
      if (ma[nx][ny].t == -1 || ma[nx][ny].t > t)
        ma[nx][ny].t = t;
    }
  }

  queue<node> q;
  ma[0][0].vis = 1;
  ma[0][0].s = 0;
  q.push(ma[0][0]);
  while (q.size()) {
    node p = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int nx = p.x + dx[i];
      int ny = p.y + dy[i];
      // 检验边界和访问
      if (nx < 0 || ny < 0 || ma[nx][ny].vis == 1)
        continue;
      // 找到安全点
      if (ma[nx][ny].t == -1) {
        cout << p.s + 1;
        return 0;
      }
      // 走到这点的步数小于流星落下的时间
      if (p.s + 1 < ma[nx][ny].t) {
        ma[nx][ny].vis = 1;
        ma[nx][ny].s = p.s + 1;
        q.push(ma[nx][ny]);
      }
    }
  }
  cout << -1;
}