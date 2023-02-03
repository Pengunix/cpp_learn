#include <iostream>
using namespace std;

// 函数对象的概念：
// 重载函数调用运算符的类，其对象称为函数对象
// 函数对象使用重载的（）时，行为类似函数调用，也叫仿函数
// 本质：
// 函数对象是一个类 不是函数

// 特点：
// 函数对象可以像普通函数那样调用，可以有参数，可以有返回值
// 函数对象超出普通函数的概念，函数对象可以有自己的状态
// 函数对象可以作为参数传递

class Add {
public:
  int operator()(int v1, int v2) { return v1 + v2; }
};

class myPrint {
public:
  int count = 0;
  void operator()(string str) {
    cout << str << endl;
    this->count += 1;
  }
};

void test() {
  Add ad;
  cout << ad(10, 23) << endl;

  myPrint print;
  print("aaa");
  print("aaa");
  print("aaa");
  print("aaa");
  print("aaa");

  cout << print.count << endl;
}

int main() { test(); }
