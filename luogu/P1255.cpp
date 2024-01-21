// AC
#include <iostream>
#include "../utils/普通高精度.cpp"
using namespace std;
using ll = long long;
// 这题注意高精度位数，如果出现前导零说明位数不够。
int main() {
  int N;
  cin >> N;
  Int f[5010];
  f[1] = Int(1);
  f[2] = Int(2);

  for (int i = 3; i <= N; i++) {
    f[i] = f[i - 2] + f[i - 1];
  }
  f[N].print();

  return 0;
}