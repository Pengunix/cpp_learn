/***
    > File Name: typedef_enum.cpp
# File Name: typedef_enum.cpp
# Author : TyhiLa
# QQ : 3055255696
# Email:hoshimaemi@outlook.com
# Blog：Null
# Created Time: Thu 19 May 2022 10:48:24 AM CST
 **/

#include <iostream>
using namespace std;
typedef int feet;

int main() {
	feet a = 1;
	// red=0 green=5 blue=6 
	enum color { red, green=5, blue } c;
	c = red;
    enum bb {e=1, f=4, g};
    bb d = g;
	cout << c << endl;
	cout << a << endl;
    cout << d << endl;
	return 0;
}
