#include <iostream>
#include <vector>
using namespace std;
// vector 也称为单端数组 数组是静态空间 而vector 可以动态扩展
// 动态扩展 并不是在原空间之后接续新空间 而是找更大的空间，然后将原数据拷贝到新空间，释放原空间
void print(vector<int> &v) {
  for (int &i : v) {
    cout << i << " ";
  }
  cout << endl;
}

void printAttr(vector<int> &v) {
  cout << "size: " << v.size() << endl;
  cout << "capacity: " << v.capacity() << endl;
}

// 构造
void test() {
  vector<int> v1;
  for (int i=0;i<10;i++) {
    v1.push_back(i);
  }
  print(v1);

  vector<int> v2(v1.begin(), v1.end());
  print(v2);

  vector<int> v3(v2);
  print(v3);
}
// 赋值
void test1() {
  vector<int> v1;
  for (int i=0;i<10;i++) {
    v1.push_back(i);
  }

  vector<int> v2 = v1;
  print(v2);

  vector<int> v3;
  v3.assign(v1.begin(), v1.end());
  print(v3);

  vector<int> v4;
  v4.assign(10, 0);
  print(v4);
}
// 容量和大小
void test2() {
  vector<int> v1;
  for (int i=0;i<10;i++) {
    v1.push_back(i);
  }
  
  cout << (bool)v1.empty() << endl;
  cout << v1.capacity() << endl;
  cout << v1.size() << endl;
 
  // 缩短会删除超出的部分
  v1.resize(20);
  // 以0填充增长的部分
  v1.resize(20, 0);

  cout << v1.capacity() << endl;
  cout << v1.size() << endl;
}

// 插入和删除
void test3() {
  // 尾部插入
  vector<int> v1;
  for (int i=0;i<10;i++) {
    v1.push_back(i);
  }

  // 尾部删除
  v1.pop_back();

  vector<int>::iterator it = v1.begin();
  it++;
  // 插入
  v1.insert(it, 5);
  print(v1);

  // 删除
  it++;
  // v1.erase(it);
  v1.erase(it, v1.end());
  print(v1);

  // 清空
  v1.clear();
  print(v1);
}

// 数据存取
void test4() {
  vector<int> v1;
  for (int i=0;i<10;i++) {
    v1.push_back(i);
  }

  cout << v1[0] << endl;

  // 有越界检查
  cout << v1.at(0) << endl;

  cout << v1.front() << endl;
  
  cout << v1.back() << endl;
}

// 互换容器
void test5() {
  vector<int> v1;
  for (int i=0;i<10;i++) {
    v1.push_back(i);
  }

  vector<int> v2;
  for (int i=10;i<20;i++) {
    v2.push_back(i);
  }

  print(v1);
  print(v2);

  v1.swap(v2);

  print(v1);
  print(v2);
}

void test6() {
  vector<int> v;
  for (int i=0; i<100000; i++) {
    v.push_back(i);
  }
  printAttr(v);

  v.resize(3);

  printAttr(v);

  // 巧用swap可以收缩内存空间
  vector<int>(v).swap(v);

  printAttr(v);

  // 预置空间 减少vector 扩展容量次数
  v.reserve(100);

  printAttr(v);
}

void test7() {
  // 统计分配次数
  int num = 0;
  int * p = NULL;
  vector<int> v;

  v.reserve(100000);

  for (int i=0; i<100000; i++) {
    v.push_back(i);
    if (p != &v[0]) {
      p = &v[0];
      num++;
    }
  }
  cout << "num: " << num << endl;

}

int main() {
  // test();
  // test1();
  // test2();
  // test3();
  // test4();
  // test5();
  // test6();
  test7();
}
