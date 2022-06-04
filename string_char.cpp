/***
############################
# File Name: string_char.cpp
# Author : TyhiLa
# QQ : 3055255696
# Email:hoshimaemi@outlook.com
# Blog：Null
# Created Time: Fri 20 May 2022 09:29:09 AM CST
 **/

#include <iostream>
#include <string>
using namespace std;
int main() {
	// 字符只能放一个，且只能使用单引号
	char a = 'b';
	// C风格字符串 []表示长度为定义长度
	char str1[] = "hello";
	// Cpp风格 
	string str2 = "hello";
	cout << a << str1 << str2;
	cout << sizeof(a);
}
