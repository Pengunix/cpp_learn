/***
############################
# File Name: func_pointer.cpp
# Author : TyhiLa
# QQ : 3055255696
# Email:hoshimaemi@outlook.com
# Blog：Null
# Created Time: Mon 05 Sep 2022 06:22:14 PM CST
 **/

#include <iostream>
using namespace std;

int test(int a) {
    return a;
}

int test1(int (*func)(int), int b) {
    int c = func(10) + b;
    return c;
}

int main() {
    // 返回值类型 (*指针名字)(形参) = 函数;
    int (*p)(int a) = test;
    cout << p(2) << endl;
    // typedef 返回值类型 (*定义类型名) (形参)
    typedef int (*fp)(int a);
    fp f = test;
    cout << f(2) << endl;

    cout << test1(f, 1) << endl;
    return 0;
}
