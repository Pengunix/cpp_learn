#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
using ll = long long;
const int N = 400 + 10;
const ll inf = 4e18, p = 998244353;
int n, m;
int g[N][N];
int dx[] = {-2, -1, 1, 2, -1, -2, 1, 2};
int dy[] = {-1, -2, -2, -1, 2, 1, 2, 1};

// dfs 超时，改bfs
void dfs(int sx, int sy, int sum) {
  g[sx][sy] = sum;
  for (int i = 0; i < 8; ++i) {
    int x = sx + dx[i];
    int y = sy + dy[i];
    if (!(x <= 0 || x > n || y <= 0 || y > m) &&
        (sum + 1 < g[x][y] || g[x][y] == -1)) {
      dfs(x, y, sum + 1);
    }
  }
}

struct node {
  int x, y, sum;
};

void bfs(int sx, int sy) {
  queue<node> q;
  g[sx][sy] = 0;
  q.push({sx, sy, 0});

  while (q.size()) {
    node z = q.front();
    q.pop();

    for (int i = 0; i < 8; ++i) {
      int x = z.x + dx[i];
      int y = z.y + dy[i];
      if (!(x <= 0 || x > n || y <= 0 || y > m) && g[x][y] == -1) {
        g[x][y] = z.sum + 1;
        q.push({x, y, z.sum + 1});
      }
    }
  }
}

int main() {
  int x, y;
  cin >> n >> m >> x >> y;
  memset(g, -1, sizeof g);
  // dfs(x, y, 0);
  bfs(x, y);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++)
      printf("%-5d", g[i][j]);
    cout << endl;
  }
}