#include <future>
#include <iostream>
using namespace std;

int main() {
  std::packaged_task<int(int, int)> task([](int a, int b) { return a + b; });
  future<int> mf = task.get_future();
  // task(12, 13);
  thread t(std::move(task), 5, 6);
  cout << mf.get() << endl;
  t.join();
}