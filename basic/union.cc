#include <cstring>
#include <iostream>
using namespace std;

union {
  unsigned char word[8];
  struct {
    unsigned int a;
    unsigned int b;
  };
} u1;

int main() {
  // 0-3 = a, 4-7 = b    低位 -> 高位
  unsigned char a[8] = {0x00, 0xFF, 0x00, 0xF0, 0x00, 0xFF, 0x00, 0xFA};
  memcpy(u1.word, a, 8);

  cout << u1.a << " " << u1.b;
}