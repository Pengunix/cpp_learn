/***
    > File Name: switch_case.cpp
# File Name: switch_case.cpp
# Author : TyhiLa
# QQ : 3055255696
# Email:hoshimaemi@outlook.com
# Blog：Null
# Created Time: Thu 19 May 2022 04:12:23 PM CST
 **/

#include <iostream>
using namespace std;

int main()
{
    // 局部变量声明
    char grade = 'D';

    switch (grade) {
    case 'A':
        cout << "很棒！" << endl;
        break;
    case 'B':
    case 'C':
        cout << "做得好" << endl;
        break;
    case 'D':
        cout << "您通过了" << endl;
        break;
    case 'F':
        cout << "最好再试一下" << endl;
        break;
    default:
        cout << "无效的成绩" << endl;
    }
    cout << "您的成绩是 " << grade << endl;

    return 0;
}
