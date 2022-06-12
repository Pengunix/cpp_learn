/***
############################
# File Name: null_pointer.cpp
# Author : TyhiLa
# QQ : 3055255696
# Email:hoshimaemi@outlook.com
# Blog：Null
# Created Time: Fri 20 May 2022 08:46:15 PM CST
 **/
// 空指针本质就是 #define NULL 0
#include <iostream>
using namespace std;
int main() {
    int *p = NULL;

    cout << p << endl;
}
