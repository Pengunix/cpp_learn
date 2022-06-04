/***
############################
# File Name: pointer.cpp
# Author : TyhiLa
# QQ : 3055255696
# Email:hoshimaemi@outlook.com
# Blog：Null
# Created Time: Fri 20 May 2022 06:37:52 PM CST
 **/

#include <iostream>

using namespace std;

int main()
{
    int var = 20; // 实际变量的声明
    int *ip;      // 指针变量的声明

    ip = &var; // 在指针变量中存储 var 的地址

    cout << "Value of var variable: ";
    cout << var << endl;

    // 输出在指针变量中存储的地址
    cout << "Address stored in ip variable: ";
    cout << ip << endl;

    // 访问指针中地址的值
    cout << "Value of *ip variable: ";
    cout << *ip << endl;

    return 0;
}
