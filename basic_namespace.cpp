#include <iostream>
using namespace std;

int g_a = 1000;
namespace SpaceA {
  int g_a = 100;
}
namespace SpaceB {
  int a = 10;
  namespace SpaceC {
    int a = 20;
  }
}

int main() {
  cout << g_a << endl;
  cout << SpaceA::g_a << endl;

  using SpaceA::g_a;
  cout << g_a << endl;

  using namespace SpaceA;
  cout << g_a << endl;

  cout << SpaceB::a << endl;
  cout << SpaceB::SpaceC::a << endl;
}
