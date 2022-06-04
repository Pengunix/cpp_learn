/***
############################
# File Name: a.cpp
# Author : TyhiLa
# QQ : 3055255696
# Email:hoshimaemi@outlook.com
# Blog：Null
# Created Time: Fri 27 May 2022 10:03:05 AM CST
 **/

#include <iostream>
using namespace std;
int main() {
    char arr[] = "aaa";
    int* p = (int *)&arr;
    cout << p << endl;
    return 0;
}
