#include <iostream>
#include <map>
#include <utility>
using namespace std;

// map 中所有元素都是pair
// pair 中第一个元素为key (键) 起到索引作用，第二个元素称为 value(值)
// 所有元素都会根据键值进行自动排序
// map/multimap也是关联式容器 底层是二叉树
// 优点
// 可以根据key快速找到value
// map 和 multimap区别 
// multimap 可以有重复key

void print(map<int, int>&m) {
  for (const pair<int, int> &p : m) {
    cout << "key: " << p.first << " value: " << p.second << endl;
  }
}
template <typename T1, typename T2>
void print(map<T1, T2> &m) {
  for (typename map<T1, T2>::iterator it = m.begin(); it!=m.end() ; it++) {
    cout << "key: " << (*it).first << " value: " << it->second << endl;
  }
}

void test() {
  // 构造与赋值
  map<int, int> m;
  m.insert(pair<int, int>(1, 2));
  m.insert(pair<int, int>(2, 28));
  m.insert(pair<int, int>(3, 98));
  m.insert(pair<int, int>(4, 75));

  print(m);

  print<int, int> (m);
  // 构造函数和operator=省略
  // 大小和交换
  map<int, int> m1;
  m1.insert(pair<int, int>(1, 7));

  m1.swap(m);

  cout << m.size() << endl;
  cout << m1.size() << endl;

  cout << (bool)m.empty() << endl;

  m.erase(m.begin());
  m1.clear();
  // 查找和统计和set相同 但map只找key
  // map<int, int>::iterator it;
  // it = m.find(1);
  // cout << m.count(0) << endl;
  // 排序也相同

}

int main() {
  test();
}
