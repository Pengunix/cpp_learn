#include <iostream>
#include <queue>
using namespace std;
using ll = long long;
const int N = 100 + 10;
const ll inf = 4e18, p = 998244353;
int n, m;
char a[N][N];
int dx[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

struct point {
  int x, y;
};

void bfs(int i, int j) {
  queue<point> q;
  a[i][j] = '.';
  q.push({j ,i});
  while (q.size()) {
    point t = q.front();
    q.pop();
  
    for (int i = 0; i <= 7; ++i) {
      int nx = t.x + dx[i];
      int ny = t.y + dy[i];

      if (nx > 0 && ny > 0 && nx <= m && ny <= n && a[ny][nx] == 'W') {
        a[ny][nx] = '.';
        q.push({nx, ny});
      }
    }
  }

}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  int ans = 0;

  for (int i=1;i<=n;++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j];
    }
  }
  for (int i=1;i<=n;++i) {
    for (int j = 1; j <= m; ++j) {
      if (a[i][j] == 'W') {
        bfs(i, j);
        ans++;
      }
    }
  }
  cout << ans;
}