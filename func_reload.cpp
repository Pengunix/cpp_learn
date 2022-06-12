/***
############################
# File Name: func_reload.cpp
# Author : TyhiLa
# QQ : 3055255696
# Email:hoshimaemi@outlook.com
# Blog：Null
# Created Time: Sun 12 Jun 2022 11:05:31 AM CST
 **/
// 函数重载
// 函数名可以相同 提高复用性
// 函数重载需要满足的条件
// 同一作用域下
// 函数名相同
// 函数参数类型不同 或者个数不同 顺序不同 反正就是不一样
#include <iostream>
using namespace std;

void func() {
    cout << "test" << endl;
}
// 参数不同，不然编译出错
void func(int) {
    cout << "test reload" << endl;
}
// 函数的返回值不可作为函数重载的条件
// int func(){...}
// 注意事项
// 1. 引用作为重载的条件
void foo(int &a) {
    cout << "call foo" << endl;
}
// 类型不同
void foo(const int &a) {
    cout << "call foo const" << endl;
}
// 2. 函数重载遇到默认参数
// 语法可以通过 但仍会产生歧义
// 函数重载尽量不要使用默认参数
/*
void bar(int a) {
    cout << "call bar" << endl;
}
void bar(int a, int b=10) {
    cout << "call bar" << endl;
}
*/
int main() {
    // 不同参数 执行不同的代码
    // func(1);
    // 调用 foo(int &a)
    //int a = 10;
    // 调用 foo(const int &a)
    const int a = 10;
    foo(a);
    // 调用foo(const int &a)  int &a = 10; 不合法的 而 const int &a= 10 合法
    // 编译创建了临时数据空间
    // 所以调用这个
    foo(10);
    return 0;
}
