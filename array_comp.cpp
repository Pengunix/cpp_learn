/***
############################
# File Name: array_comp.cpp
# Author : TyhiLa
# QQ : 3055255696
# Email:hoshimaemi@outlook.com
# Blog：Null
# Created Time: Sat 21 May 2022 07:31:09 PM CST
 **/
// 数组取最大
#include <iostream>
using namespace std;
int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 3, 5, 10 };
    int m = 0;
    // &表示i为引用变量
    for (int& i : arr) {
        if (i>m) {
            m = i;
        }
    }
    cout << m << endl;
    return 0;
}
