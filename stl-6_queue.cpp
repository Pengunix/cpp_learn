#include <iostream>
#include <queue>
using namespace std;

// First In First Out FIFO 先进先出
// 不可遍历

int main() {
  queue<int> que;
  que.push(1);
  que.push(2);
  que.push(3);

  cout << que.size() << endl;

  while(!que.empty()) {
    cout << que.front() << " " << que.back() << endl;
    que.pop();
  }
}
