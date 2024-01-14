#include <iostream>
#include <list>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;

int main() {
  list<int> l{1, 2, 3};
  list<int>::iterator it = l.end();
  cout << *(it++);
  cout << *(it++);
}