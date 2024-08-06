#include <chrono>
#include <iostream>
#include <semaphore>
#include <thread>
#include <vector>

// 第一个1,指定了信号量的最大计数值，也就是可以同时访问多少个资源
// 第二个1,指定了信号量的初始值，表示当前有多少可访问的资源
std::counting_semaphore<1> sem(1);
void worker(int id) {
  sem.acquire(); // P操作，在信号量大于0时将其减1,等于0时等待
  std::cout << sem.max() << std::endl;
  std::cout << "Worker" << id << " is working\n";
  std::this_thread::sleep_for(std::chrono::seconds(1));
  std::cout << "Worker" << id << " is done\n";
  sem.release(); // V操作，将信号量加1,并唤醒阻塞的进程
}

int main() {
  std::vector<std::thread> threads;
  for (int i = 0; i < 5; ++i) {
    threads.emplace_back(worker, i);
  }
  for (auto &t : threads) {
    t.join();
  }
}