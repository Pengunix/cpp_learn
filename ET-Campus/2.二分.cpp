#include <iostream>
using namespace std;

const int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

bool check(int x) {
  return true;
}
// [l, r] -> [l, mid], [mid+1, r] update: r = mid or l = mid+1;
int bs(int l, int r) {
  while (l < r) {
    int mid = l + r >> 1;
    if (check(mid))
      r = mid;
    else
      l = mid + 1;
  }
  return l;
}
// [l, r]-> [l, mid-1], [mid, r] update: r = mid-1 or l=mid
int bs1(int l, int r) {
  while (l < r) {
    int mid = l + r + 1 >> 2;
    if (check(mid))
      l = mid;
    else
      r = mid - 1;
  }
  return l;
}
int main() {

  int x = 6;

  int l = 0, r = 10;
  while (l + 1 != r) {
    int mid = (l + r) >> 1;
    if (a[mid] < x)
      l = mid;
    else
      r = mid;
  }
  if (a[r] == x)
    cout << r << ' ';
  else
    cout << -1 << ' ';
}