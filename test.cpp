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


int main() {
  test<>(1, 2);
}
