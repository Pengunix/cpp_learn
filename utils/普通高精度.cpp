#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;

struct Int {
  int len, a[100];
  Int(int x = 0) {
    memset(a, 0, sizeof(a));
    for (len = 1; x; len++)
      a[len] = x % 10, x /= 10;
    len--;
  }
  int &operator[](int i) {
    return a[i];
  }
  
  void flatten(int L) {
    len = L;
    for (int i = 1; i <= len; i++) {
      a[i+1] +=a[i] / 10, a[i]%=10;
    }
    for (; !a[len];) {
      len--;
    }
  }
  void print() {
    for (int i = max(len, 1); i >= 1; i--)
      cout << a[i];
  }
};
Int operator+(Int& a, Int& b) {
    Int c;
    int len = max(a.len, b.len);
    for (int i = 1; i <= len; i++)
      c[i] += a[i] + b[i];
    c.flatten(len + 1);
    return c;
}
Int operator*(Int a, int b) {
    Int c;
    int len = a.len;
    for (int i = 1; i <= len; i++)
      c[i] = a[i] * b;
    c.flatten(len + 11);
    return c;
}
ostream &operator<<(ostream &out, const Int &x) {
  for (int i = x.len - 1; i >= 0; --i)
    cout << x.a[i];
  return out;
}