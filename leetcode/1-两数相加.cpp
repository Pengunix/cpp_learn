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

list<int> tolist(int a) {
  list<int> ret;
  while (a!=0) {
    ret.push_front(a%10);
    a/=10;
  }
  return ret;
}

int main() {
  list<int> a{9, 9, 9};
  list<int> b{9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9};

  int c = toint(a);
  int d = toint(b);
  int ret = c + d;

  list<int> rr;
  rr = tolist(ret);
  for (int i:rr) {
    cout << i << " ";
  }
  cout << endl;

}