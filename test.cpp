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
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int* p = a;
    for (int i=0;i<10;i++) {
        cout << *(p+i) << endl;
    }
    return 0;
}
