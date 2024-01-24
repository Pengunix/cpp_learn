#include <iostream>
#include <string>
using namespace std;

string expand() {
  string s = "", X;
  char c;
  int D;
  while (cin >> c) {
    if (c == '[') {
      cin >> D;
      X = expand();
      while (D--) s+= X;
    } else if (c == ']')
      return s;
    else s += c;
  }
  return s;
}

int main() {
  cout << expand();
  return 0;
}