/***
############################
# File Name: char_pointer.cpp
# Author : TyhiLa
# QQ : 3055255696
# Email:hoshimaemi@outlook.com
# Blog：Null
# Created Time: Fri 20 May 2022 07:46:50 PM CST
 **/

#include <iostream>

using namespace std;
const int MAX = 3;

int main()
{
    char var[MAX] = { 'a', 'b', 'c' };
    char* ptr;

    // 指针中的数组地址
    ptr = var;
    // 使用指针遍历字符组
    for (int i = 0; i < MAX; i++) {

        cout << "Address of var[" << i << "] = ";
        // 强转字符型指针为整型 否则会输出字符组
        cout << (int*)ptr << endl;

        cout << "Value of var[" << i << "] = ";
        cout << *ptr << endl;
        cout << &var << endl;
        // 移动到下一个位置
        ptr++;
    }
    return 0;
}
