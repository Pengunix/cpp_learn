/***
############################
# File Name: gp-1_template_func.cpp
# Author : TyhiLa
# QQ : 3055255696
# Email:hoshimaemi@outlook.com
# Blog：Null
# Created Time: Thu 29 Dec 2022 01:30:00 PM CST
 **/

#include <iostream>
using namespace std;
// 函数模板 typename 可以换为 class
// 两者区别：
//       当T为包含子类的类时 不能用class 编译器会误以为是对象声明
//       建议用typename
// 函数模板和普通函数区别
//       普通函数调用时可以发生自动类型转换（隐式类型转换）
//       函数模板调用时，如果使用自动类型推导，不会发生隐式类型转换
//       如果使用显式指定类型的方式，可以发生隐式类型转换
// 普通函数和函数模板区别
//       调用规则如下
//       1. 如果函数模板和普通函数都可以实现，优先调用普通函数
//       2. 可以通过空模板参数列表来强制调用函数模板
//       3. 函数模板也可以发生重载
//       4. 如果函数模板可以产生更好的匹配，优先调用函数模板
// 模板的局限性
//       无法处理数组、对象等自定义类型
//       为了解决这种问题，提供模板的重载，可为这些特定的类型提供具体化的模板
//       测试代码在gp-3
template <typename T> void aswap(T &a, T &b) {
  T temp = a;
  a = b;
  b = temp;
}

int main() {
  int a = 1;
  int b = 2;
  double c = 3.1;
  double d = 4.4;
  // 指定T 类型
  aswap<int>(a, b);
  // 自动推导 必须推导出一致的数据类型T，才可以使用
  // 错误: aswap(int, double)
  // 模板必须要确定出T 的数据类型，才可以使用
  // template<typename T>
  // void func();
  // 此函数模板必须指定T才可以调用 因为编译器不能根据函数体推导类型
  // func<int>();
  aswap(c, d);

  cout << "a: " << a << endl;
  cout << "b: " << b << endl;
  cout << "c: " << c << endl;
  cout << "d: " << d << endl;
}
