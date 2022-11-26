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
    int x=100,y=200,z=300;
    //         捕获外部变量 参数  函数体 返回值类型
    //         变量捕获(capture clause)
    //         [N, &M] 分别为值捕获和引用捕获
    //         [&] 引用捕获所有封闭范围内的变量
    //         [=] 值捕获所有封闭范围内的变量
    //         [&, =N] 单独指定一些变量按值捕获
    //         [=, &N] 单独指定一些变量按引用捕获
    //         [this] 在类内捕获this指针
    //         [*this] 类内按值捕获实例
    //         [w=10]c++14在捕获中创建新变脸
    //         参数列表可以使用auto
    //         [] (auto a, auto b) {return a+b;}
    auto ff = [=,&y,&z,w=10](int n) -> int {
        cout << x << endl;
        cout << w << endl;
        y++; z++;
        return n*n;
    };
    cout << ff(15) << endl;
    cout << y << "," << z << endl;
}
