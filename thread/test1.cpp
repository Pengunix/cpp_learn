#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

std::mutex lck;
int count = 0;

void task1() {
  for (int i = 1; i <= 10000; i++) {
    lck.lock();
    count++;
    lck.unlock();
  }
}

int main() {
  std::vector<std::thread> v;
  for (int i = 1; i <= 10; i++) {
    v.emplace_back(task1);
  }
  for (std::thread &i : v) {
    i.join();
  }
  std::cout << count << std::endl;
}