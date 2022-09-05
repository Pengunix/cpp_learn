/***
############################
# File Name: oop_operator_reload5.cpp
# Author : TyhiLa
# QQ : 3055255696
# Email:hoshimaemi@outlook.com
# Blog：Null
# Created Time: Mon 05 Sep 2022 06:43:25 PM CST
 **/
// 函数调用运算符重载 仿函数
#include <iostream>
using namespace std;

class MyPrint {
public:
    void operator() (string text) {
        cout << text << endl;
    }
};

void test() {
    MyPrint print;
    print("aaa");
    // MyPrint("aaa") 此处调用的是有参构造报错
    MyPrint() ("aaa"); // 此处使用匿名对象来使用重载
}
int main() {
}
