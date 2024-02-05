#include <algorithm>
#include <iostream>
using namespace std;

const int N = 1e5 + 7;
struct Node {
  int v, id;
  bool operator<(const Node a) const {
    return v < a.v;
  }
} a[N];

int n, rankk[N];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].v;
    a[i].id = i;
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++)
    rankk[a[i].id] = i;
}