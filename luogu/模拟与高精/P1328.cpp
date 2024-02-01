#include <iostream>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;

int a[200], b[200];
int reta = 0, retb = 0;
// 选打表，索引从零开始减少麻烦
int vs[5][5] = {{0,0,1,1,0},{1,0,0,1,0},{0,1,0,0,1},{0,0,1,0,1},{1,1,0,0,0}};
int main() {
  int n, na, nb;
  cin >> n >> na >> nb;

  for (int i = 0; i < na; ++i) {
      cin >> a[i];
  }
  for (int i = 0; i < nb; ++i) {
      cin >> b[i];
  }

  for (int i = 0; i < n; ++i) {
    reta += vs[a[i%na]][b[i%nb]];
    retb += vs[b[i%nb]][a[i%na]];
  }
  cout << reta << ' ' << retb;
}