#include <barrier>
#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

void worker(int id, std::barrier<> &sync_point) {
  std::cout << "worker" << id << " is doing phase 1 work" << std::endl;
  std::this_thread::sleep_for(std::chrono::seconds(1 * id));

  sync_point.arrive_and_wait();
  std::cout << "worker" << id << " pahse is done and doing phase 2 work"
            << std::endl;
  ;
  std::this_thread::sleep_for(std::chrono::seconds(1 * id));
}

int main() {
  const int num_threads = 5;
  std::barrier sync_point(num_threads);
  std::vector<std::thread> threads;
  for (int i = 0; i < 5; i++) {
    threads.emplace_back(worker, i + 1, std::ref(sync_point));
  }
  for (auto &t : threads) {
    t.join();
  }

  std::cout << "All done \n";
}