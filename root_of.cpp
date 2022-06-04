/***
############################
# File Name: root_of.cpp
# Author : TyhiLa
# QQ : 3055255696
# Email:hoshimaemi@outlook.com
# Blog：Null
# Created Time: Sat 21 May 2022 09:26:02 AM CST
 **/

#include <cmath>
#include <iostream>
using namespace std;
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    // cout << a << b << c;
    int delta = b * b - 4 * a * c;
    cout << "delta: " << delta << endl;
    if (delta > 0) {
        int x1 = (-b + pow(delta, 0.5)) / (2 * a);
        int x2 = (-b - pow(delta, 0.5)) / (2 * a);
        cout << x1 << "  " << x2 << endl;
    } else if (delta == 0) {
        int x = (-b + pow(delta, 0.5)) / (2 * a);
        cout << x;
    } else {
        cout << "无实根";
    }
    return 0;
}
