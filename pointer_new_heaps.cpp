/***
############################
# File Name: new_heaps.cpp
# Author : TyhiLa
# QQ : 3055255696
# Email:hoshimaemi@outlook.com
# Blog：Null
# Created Time: Tue 07 Jun 2022 04:00:38 PM CST
 **/

#include <iostream>
using namespace std;
int * func() {
    // 栈区数据在程序运行结束后 自动回收 此时程序失去堆栈区数据的控制权
    // 那么我们可以用堆区 来解决此问题
    // 利用new关键字 可以将数据放在堆区
    // 这个指针本质也是一个局部变量 放在栈区，保存的数据放在堆区
    int * p = new int(10);
    // 在堆区开启一个数组
    // 创建长度为10的数组 并随机赋值 返回首地址
    int * arr = new int[10];
    for (int i=0;i<10;i++){
        arr[i] = i +100;
    }
    // 释放数组 加 []
    delete[] arr;
    return p;
}
int main() {
    int *p  = func();
    cout << *p << endl;
    delete p;
    // cout << *p << endl; 报错
    // cout << (int)p << endl; 报错 指针连同数据一起删除
    return 0;
}
