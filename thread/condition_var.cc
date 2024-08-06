#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>

std::mutex mtx;
std::condition_variable cv;
bool ready = false;
void threadFunction() {
  // 等待通知
  std::unique_lock<std::mutex> lck(mtx);
  cv.wait(lck, [] { return ready; });

  // 线程开始工作
  std::cout << "Thread is running..." << std::endl;
}

int main() {
  // 创建线程，但线程函数会等待直到收到通知
  std::thread t(threadFunction);

  // 模拟一些主线程的工作
  std::this_thread::sleep_for(std::chrono::seconds(2));
  std::cout << "Main thread is ready to start the worker thread" << std::endl;

  // 通知线程可以开始工作
  {
    std::lock_guard<std::mutex> lck(mtx);
    ready = true;
  }
  cv.notify_one();

  // 等待线程完成
  t.join();

  return 0;
}