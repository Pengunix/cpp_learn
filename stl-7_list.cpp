#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

// 链表 STL提供的是双向循环链表
// 优点：可对任意位置快速添加和删除
//       动态存储分配，减少内存浪费和溢出
// 缺点：对容器的遍历速度较慢
//       占用空间大
// 由于链表的存储不是连续的内存，因此链表的迭代器只支持前移和后移，属于双向迭代器
// 插入和删除不会影响迭代器位置 vector 不同


void print(const list<int>  &li) {
  for (list<int>::const_iterator it=li.begin();it != li.end();it++) {
    cout << *it << " ";
  }
  cout << endl;
}


// 接口 list 不能使用[] .at() 来访问 基本相同
// 反转和排序
void test() {
  list<int> li;
  li.push_back(89);
  li.push_back(76);
  li.push_back(54);
  li.push_back(90);

  print(li);
  li.reverse();
  print(li);

  li.sort();
  print(li);
}

int main() {
  test();
}
