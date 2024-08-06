#include <atomic>
#include <iostream>
#include <thread>

std::atomic<int> aint(0);

void add_one() {
  for (int i = 0; i < 100000; i++) {
    aint++;
    // aint += 1
    // aint = aint + 1; 非原子操作
  }
}

int main() {
  std::thread t1(add_one);
  std::thread t2(add_one);
  t1.join();
  t2.join();
  std::cout << aint << std::endl;
}