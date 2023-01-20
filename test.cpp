#include <fstream>
#include <iostream>
using namespace std;

template<typename T>
void test(T a, T b) {
  cout << "temp aa" << endl;
}
void test(int  a, int b) {
  cout << "aa" << endl;
}

struct A {
  int a;
  int b;
};

int main() {
  A c;
  c = {10, 10};
  A * p = &c;
  p->
  

}
