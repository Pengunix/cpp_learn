#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

void print(const deque<int> &d) {
  for (deque<int>::const_iterator it = d.begin();it != d.end();it++) {
    cout << *it << " ";
  }
  cout << endl;
}

// 插入和删除
void test() {
  deque<int> d;
  
  d.push_front(11);
  d.push_back(12);
  print(d);

  d.pop_front();
  d.pop_back();
  cout << (bool)d.empty() << endl;

  d.insert(d.begin(), 1000);

  d.insert(d.begin(), 2, 2000);

  print(d);

  deque<int>::iterator it = d.begin();
  it++;
  d.erase(it);
  print(d);

  cout << d.front() << endl;
  cout << d.back() << endl;
}
// 排序
void test1() {
  deque<int>  d;
  d.push_back(10);
  d.push_back(20);
  d.push_back(30);
  d.push_front(45);
  d.push_front(35);
  d.push_front(99);

  sort(d.begin(), d.end());

  print(d);
}

int main() {
  // test();
  test1();
}
