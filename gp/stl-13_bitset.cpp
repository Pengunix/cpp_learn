// 位组
// 支持位运算，不支持四则运算
// 左高右低 按照权重排列
// 给定n个整数，这些整数通过加法操作可以组成多少种数字。  
#include <bitset>
#include <iostream>
using namespace std;
using ll = long long;
const int N = 5e5 + 10;
int a[N];


int main(int argc, const char **argv) {

  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  bitset<N> bs;
  bs[0] = 1;
  for (int i = 1; i <= n; ++i) {
    bs |= (bs << a[i]);
  }

  cout << bs.count() << '\n';
  return 0;
}