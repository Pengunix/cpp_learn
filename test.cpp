/***
############################
# File Name: test.cpp
# Author : TyhiLa
# QQ : 3055255696
# Email:hoshimaemi@outlook.com
# Blog：Null
# Created Time: Sat 21 May 2022 07:03:25 PM CST
 **/

#include <iostream>
using namespace std;
int main() {
    int a = 10;
    cout << &a << endl;
    int &b = a;
    cout << &b << endl;
    int * const c = &a;
    cout << c << endl;
    return 0;
}
