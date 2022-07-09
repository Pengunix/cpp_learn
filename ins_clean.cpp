/***
############################
# File Name: ins_clean.cpp
# Author : TyhiLa
# QQ : 3055255696
# Email:hoshimaemi@outlook.com
# Blog：Null
# Created Time: Sun 03 Jul 2022 06:14:51 PM CST
 **/
// 对象的初始化和清理
// instance intialize and clean up.

#include <iostream>
using namespace std;
// 构造函数与析构函数
class test {
public:
    // 构造函数 函数名与类名相同
    // 没有返回值 也不写void
    // 构造函数可以有参数，因此可以发生重载
    // 程序在调用对象时会自动调用构造 无需手动调用 且只会调用一次
    test() {
        cout << "调用" << endl;

    }

    // 析构函数 函数名与类名相同 但加一个波浪线
    // 同样无返回值 不用写void
    // 析构函数不可有参数 因此不可以重载
    // 程序会在对象销毁前自动调用析构函数，无需手动调用 且只会调用一次
    ~test() {
        cout << "销毁" << endl;
    }

};
// 构造和析构都是必须有的实现，
// 如果不自己实现，编译器会提供一个空实现的构造和析构
void test01() {
    test p; // 在栈上的数据 执行完毕后 释放这个对象
}
int main() {
    test p;
    return 0;
}
