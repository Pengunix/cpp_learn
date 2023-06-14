/***
############################
# File Name: array_reverse.cpp
# Author : TyhiLa
# QQ : 3055255696
# Email:hoshimaemi@outlook.com
# Blog：Null
# Created Time: Sun 22 May 2022 06:57:21 AM CST
 **/
// 反转一个数组
#include <iostream>
using namespace std;
int main()
{
    int a[] = { 1, 3, 2, 5, 4 };
    int len = sizeof(a) / 4;
    int b[len];
    // int *p = a;
    // p++;
    for (int i = 0; i < len; i++) {
        b[len - i - 1] = a[i];
    }
    for (int& a : b) {
        cout << a << endl;
    }
    return 0;
}
