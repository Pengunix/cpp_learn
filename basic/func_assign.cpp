/***
    > File Name: func_assign.cpp
# File Name: func_assign.cpp
# Author : TyhiLa
# QQ : 3055255696
# Email:hoshimaemi@outlook.com
# Blog：Null
# Created Time: Thu 19 May 2022 01:09:31 PM CST
 **/
#include <iostream>
using namespace std;

// 函数声明
int func(int num1, int num2);
 
int main()
{
    // 函数调用
    int i = func(1, 2);
    cout << i << endl;
}
 
// 函数定义
int func(int num1, int num2)
{
    return num1 + num2;
}
