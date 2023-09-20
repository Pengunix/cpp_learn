#include <iostream>
using namespace std;

const int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

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