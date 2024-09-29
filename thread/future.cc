#include <chrono>
#include <future>
#include <iostream>
#include <ostream>
#include <thread>

int task1(int a, int b) {
  std::cout << "addition id: " << std::this_thread::get_id() << std::endl;
  std::this_thread::sleep_for(std::chrono::seconds(1));
  std::cout << "done" << std::endl;
  return a + b;
}

int main() {
  std::cout << "main id: " << std::this_thread::get_id() << std::endl;
  // std::future<int> f1 = std::async(std::launch::async, task1, 10, 20);
  std::future<int> f1 = std::async(std::launch::deferred, task1, 10, 20);
  std::cout << f1.get() << std::endl;
}