/***
############################
# File Name: test.cpp
# Author : TyhiLa
# QQ : 3055255696
# Email:hoshimaemi@outlook.com
# Blog：Null
# Created Time: Sat 21 May 2022 06:26:31 PM CST
 **/

#include <iostream>
using namespace std;
int main() {
    for (int i=1;i<10;i++) {
        for (int j=1;j<=i;j++) {
            cout << j << "x" << i << "=" << i*j << " ";
        }
        cout << endl;
    }
}
