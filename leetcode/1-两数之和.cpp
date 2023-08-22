#include <iostream>
#include <list>
using namespace std;

int toint(list<int> x) {
  int c = 0;
  int cur = 1;
  for (int i : x) {
    i *= cur;
    c += i;
    cur *= 10;
  }
  return c;
}

list<int> tolist(int a) { int }

int main() {
  list<int> a{9, 9, 9};
  list<int> b{9, 9, 9, 9, 9, 9};

  int c = toint(a);
  int d = toint(b);
  int ret = c + d;

  cout << ret << endl;
}