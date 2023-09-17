#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  // 取消同步流 提高效率
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  // 1.scanf 和 printf
  // 仅适合格式化io
  // 15:30 scanf("%d:%d", &a, &b);
  // printf("%.5f", x);
  // 不能开取消同步流 会出错

  // 2. cin cout
  // 简洁好用，取消同步流比scanf快
  // cout << endl 尽量不用 改用\n
  // endl 换行加清空缓冲区 （交互题）
}