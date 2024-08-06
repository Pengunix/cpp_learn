#include <chrono>
#include <iostream>
#include <semaphore>
#include <thread>

// 控制worker线程
std::counting_semaphore<1> ready(0);
// 控制prepare线程
std::counting_semaphore<1> done(1);

void prepare() {
  done.acquire(); // 确保prepare 在worker 完成前不会执行
  std::cout << "Preparing..\n";
  std::this_thread::sleep_for(std::chrono::seconds(1));
  std::cout << "Preparation done\n";
  ready.release(); // 准备完成，开始工作
}

void worker() {
  ready.acquire(); // 确保准备完成后再执行
  std::cout << "Working..\n";
  std::this_thread::sleep_for(std::chrono::seconds(1));
  std::cout << "Works done\n";
  ready.release(); // 开始准备
}

int main() {
  std::thread t1(prepare);
  std::thread t2(worker);

  t1.join();
  t2.join();
  std::cout << "done\n";
}