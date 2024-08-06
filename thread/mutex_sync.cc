#include <iostream>
#include <mutex>
#include <thread>

int counter = 0;
std::mutex lck;            // 普通mutex同一个线程只能锁定一次
std::recursive_mutex rlck; // 递归mutex同一个线程可锁定多次，
                           // 同时需要解锁相应的次数
std::timed_mutex
    tlck; // 设定在一定时间内获取锁，超时tlck.try_lok_for()返回false

void increment(int times) {
  for (int i = 1; i <= times; i++) {
    // lck.lock();
    std::lock_guard<std::mutex> lock(lck);
    counter++;
    // lck.unlock();
  }
}

int main() {
  std::thread t1(increment, 100000);
  std::thread t2(increment, 100000);

  t1.join();
  t2.join();

  std::cout << counter << std::endl;
}