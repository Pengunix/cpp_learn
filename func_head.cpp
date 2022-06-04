/***
############################
# File Name: func_head.cpp
# Author : TyhiLa
# QQ : 3055255696
# Email:hoshimaemi@outlook.com
# Blog：Null
# Created Time: Sun 22 May 2022 04:08:31 PM CST
 **/

#include <iostream>
#include "func_headh.h"
using namespace std;
int main() {
    int a = 1;
    int b = 2;
    swap(a, b);
    return 0;
}
void swap(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    cout << a << b << endl;
}
