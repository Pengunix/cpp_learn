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
int test() {
    return 10;
}
int& test1() {
    static int a = 10;
    return a;
}
int * test2() {
    static int a[] = {1, 2, 3, 4, 5};
    return a;
}

int main() {
    cout << test() << endl;
    int *p = test2();
    for (int i=0;i<5;i++) {
        cout << *p++ << endl;
    }
    return 0;
}
