#include <iostream>
#include <mutex>
#include <shared_mutex>
#include <thread>
#include <vector>

std::shared_mutex rw_mtx;
int shared_data = 0;

void reader() {
  std::shared_lock lock(rw_mtx);
  std::cout << "Reader id: " << std::this_thread::get_id() << " read val; "
            << shared_data << std::endl;
}

void writer(int value) {
  std::unique_lock lock(rw_mtx);
  shared_data = value;
  std::cout << "Writer id: " << std::this_thread::get_id()
            << " write val: " << shared_data << std::endl;
}

int main() {
  std::vector<std::thread> threads;

  for (int i = 0; i < 5; i++) {
    threads.emplace_back(reader);
  }

  for (int i = 0; i < 2; i++) {
    threads.emplace_back(writer, i);
  }
  for (auto &t : threads) {
    t.join();
  }
}