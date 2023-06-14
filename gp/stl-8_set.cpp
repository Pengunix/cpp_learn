#include <cstdio>
#include <iostream>
#include <set>
using namespace std;

// 集合容器
// 每个元素在插入时自动排序
// 本质 set/multiset 属于关联式容器，底层结构是二叉树
// set/multiset 区别
// set不允许容器中有重复的元素
// multiset允许
void print(set<int> &s) {
  for (const int &i : s) {
    cout << i << " ";
  }
  cout << endl;
}

template <class T1, class T2>
void print(set<T1, T2> &s) {
  for (const int &i : s) {
    cout << i << " ";
  }
  cout << endl;
}
//
// void print(set<int, MyCompare> &s) {
//   for (set<int, MyCompare>::iterator it;it!=s.end();it++) {
//     cout << *it << " ";
//   }
//   cout << endl;
// }

// 构造和赋值
void test() {
  set<int> st;

  st.insert(10);
  st.insert(34);
  st.insert(65);
  st.insert(23);

  print(st);
  // 含有拷贝构造和operator=
  cout << st.size() << endl;
  // 不允许重新指定大小
  cout << (bool)st.empty() << endl;

  set<int> s1;
  // 为空不交换
  s1.insert(10);
  s1.swap(st);

  print(s1);
  print(st);
  // clear erase 相同
}
// 查找和统计
void test1() {
  set<int> st;

  // insert 会返回插入结果
  st.insert(10);
  st.insert(34);
  st.insert(65);
  st.insert(23);

  pair<set<int>::iterator, bool> ret = st.insert(10);
  if (ret.second) {
    cout << "Insert suceed" << endl;
  } else {
    cout << "Insert failed" << endl;
  }

  // 允许插入相同值
  multiset<int> mt;
  mt.insert(10); // 返回迭代器 没有bool
  mt.insert(10);

  // 查找 存在则返回元素的迭代器 不存在则返回set.end();
  set<int>::iterator it = st.find(34);
  if (it != st.end()) {
    cout << *it << endl;
  } else {
    cout << "Not found" << endl;
  }

  cout << (int)st.count(10) << endl;
}

// 排序
// 利用仿函数改变排序规则
class MyCompare {
public:
  bool operator()(int v1, int v2) { return v1 > v2; }
};

void test3() {
  set<int> st;

  st.insert(10);
  st.insert(34);
  st.insert(65);
  st.insert(23);

  print(st);

  set<int, MyCompare> s2;

  s2.insert(10);
  s2.insert(34);
  s2.insert(65);
  s2.insert(23);

  print<int, MyCompare>(s2);
}

int main() {
  // test();
  // test1();
  test3();
}
