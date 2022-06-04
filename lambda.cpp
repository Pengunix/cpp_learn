/***
    > File Name: lambda.cpp
# File Name: lambda.cpp
# Author : TyhiLa
# QQ : 3055255696
# Email:hoshimaemi@outlook.com
# Blog：Null
# Created Time: Thu 19 May 2022 05:11:27 PM CST
 **/

#include <iostream>
using namespace std;
int main()
{   
    int x = 100,y=200,z=300;
    auto ff  = [=,&y,&z](int n) {
        cout <<x << endl;
        y++; z++;
        return n*n;
    };
    cout << ff(15) << endl;
    cout << y << "," << z << endl;
}
