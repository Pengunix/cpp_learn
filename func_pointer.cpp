/***
############################
# File Name: func_pointer.cpp
# Author : TyhiLa
# QQ : 3055255696
# Email:hoshimaemi@outlook.com
# Blog：Null
# Created Time: Thu 26 May 2022 05:45:09 PM CST
 **/

#include <iostream>
using namespace std;
void swap(int* p1, int* p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
int main()
{
    int a = 10;
    int b = 20;
    swap(&a, &b);
    cout << a << "  " << b << endl;
}
