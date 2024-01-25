#include <iostream>
using namespace std;
using ll = long long;
const int N = 510;
int a[N][N], f[N][N], n, m, x, y, r, z;
int tmp = 1;

void Spin(int x, int y, int r, int z) {
  if (z == 0) {
    for (int i = x - r; i <= x + r; i++)
      for (int j = y - r; j <= y + r; j++)
        f[x - y + j][x + y - i] = a[i][j];
    for (int i = x - r; i <= x + r; i++)
      for (int j = y - r; j <= y + r; j++)
        a[i][j] = f[i][j];
  } else {
    for (int i = x - r; i <= x + r; i++)
      for (int j = y - r; j <= y + r; j++)
        f[x + y - j][y - x + i] = a[i][j];
    for (int i = x - r; i <= x + r; i++)
      for (int j = y - r; j <= y + r; j++)
        a[i][j] = f[i][j];
  }
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      a[i][j] = tmp++;
    }
  }

  while (m--) {
    cin >> x >> y >> r >> z;
    Spin(x, y, r, z);
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cout << a[i][j] << ' ';
    }
    cout << '\n';
  }
}