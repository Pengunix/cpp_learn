#include <iostream>
#include <mutex>
#include <thread>

std::mutex mtx;
int counter = 0;

void task() {
  std::unique_lock<std::mutex> lk1(mtx); // 创建对象就上锁
  std::unique_lock<std::mutex> lk2(mtx, std::defer_lock);  // 稍后手动上锁
  std::unique_lock<std::mutex> lk3(mtx, std::try_to_lock); // 尝试锁定
  std::unique_lock<std::mutex> lk4(mtx, std::adopt_lock); // 接受已锁定的mtx

  lk2.lock();
  lk1.owns_lock();
  lk4.try_lock();
}
