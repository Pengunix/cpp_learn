/***
############################
# File Name: array_pointer.cpp
# Author : TyhiLa
# QQ : 3055255696
# Email:hoshimaemi@outlook.com
# Blog：Null
# Created Time: Fri 20 May 2022 07:08:06 PM CST
 **/

#include <iostream>
using namespace std;

int main()
{
    // 带有 5 个元素的双精度浮点型数组
    double runoobAarray[5] = { 1000.0, 2.0, 3.4, 17.0, 50.0 };
    double* p;
    // p指针指向数组第一个元素的地址
    // 数组无需使用&符号获取地址
    // int* p = &arr[2] 获取数组中第三个元素地址
    p = runoobAarray;

    // 输出数组中每个元素的值
    cout << "使用指针的数组值 " << endl;
    for (int i = 0; i < 5; i++) {
        cout << "*(p + " << i << ") : ";
        // *运算优先级大，所以加括号
        cout << *(p + i) << endl;
    }

    cout << "使用 runoobAarray 作为地址的数组值 " << endl;
    for (int i = 0; i < 5; i++) {
        cout << "*(runoobAarray + " << i << ") : ";
        cout << *(runoobAarray + i) << endl;
    }

    return 0;
}
