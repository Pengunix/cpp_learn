/***
############################
# File Name: func_improve.cpp
# Author : TyhiLa
# QQ : 3055255696
# Email:hoshimaemi@outlook.com
# Blog：Null
# Created Time: Sun 12 Jun 2022 10:43:39 AM CST
 **/
// 默认参数
// 函数的形参列表是可以有默认值的
#include <iostream>
using namespace std;

int func1(int a=10, int b=10); // 声明带有默认参数

// 此处不能有默认参数 编译器出现歧义 “二异性”
int func1(int a, int b) {
    return a + b;
}

void func(int a, int b = 10, int c = 100) {
    // 如果某个位置有默认值，那么从这个位置往后，从左到右，必须都要有默认值
    // 如果函数声明有默认值，函数实现的时候就不能有默认参数
    cout << a << " " << b << " " << c << endl;
} 

// 占位参数 只写一个数据类型
// 目前用不到占位参数
// 占位参数可以有默认值
void funca(int a, int, int = 10) {
    cout << "test" << endl;
}

int main() {
    func(10);
    func(10, 20, 12);
    cout << func1() << endl;
    funca(1, 1);

    return 0;
}
