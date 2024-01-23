// 评测通过
#include <iostream>
using namespace std;
using ll = long long;
const int N = 1e4 + 10;

char mine_map[N][N];

int main() {
  int x, y;
  cin >> y >> x;
  char tmp;

  for (int i = 1; i <= y; ++i) {
    for (int j = 1; j <= x; ++j) {
      cin >> tmp;
      if (tmp == '*') {
        mine_map[i][j] = '*';
        mine_map[i-1][j-1] = mine_map[i-1][j-1] == '*' ? '*' : mine_map[i-1][j-1]+1; 
        mine_map[i-1][j] = mine_map[i-1][j] == '*' ? '*' : mine_map[i-1][j]+1; 
        mine_map[i-1][j+1] = mine_map[i-1][j+1] == '*' ? '*' : mine_map[i-1][j+1]+1; 
        mine_map[i][j-1] = mine_map[i][j-1] == '*' ? '*' : mine_map[i][j-1]+1; 
        mine_map[i][j+1] = mine_map[i][j+1] == '*' ? '*' : mine_map[i][j+1]+1; 
        mine_map[i+1][j-1] = mine_map[i+1][j-1] == '*' ? '*' : mine_map[i+1][j-1]+1; 
        mine_map[i+1][j] = mine_map[i+1][j] == '*' ? '*' : mine_map[i+1][j]+1; 
        mine_map[i+1][j+1] = mine_map[i+1][j+1] == '*' ? '*' : mine_map[i+1][j+1]+1; 
      }
    }
  }
  for (int i = 1; i <= y; ++i) {
    for (int j = 1; j <= x; ++j) {
      if (mine_map[i][j] == '*') {
        cout << '*';
      } else {
        cout << (int)mine_map[i][j];
      }
    }
    cout << '\n';
  }
}