#include <chrono>
#include <future>
#include <iostream>
#include <thread>
using namespace std::chrono_literals;

void task1(std::promise<int> prom) {
  std::this_thread::sleep_for(1s);
  prom.set_value(1234);
}

int main() {
  std::promise<int> prom;
  std::future<int> fut = prom.get_future();
  std::thread t(task1, std::move(prom));
  std::cout << fut.get() << std::endl;

  t.join();
  return 0;
}