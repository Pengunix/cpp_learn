/***
############################
# File Name: oop_poly_purevirfunc_abs.cpp
# Author : TyhiLa
# QQ : 3055255696
# Email:hoshimaemi@outlook.com
# Blog：Null
# Created Time: Sun 11 Dec 2022 09:12:27 AM CST
 **/

#include <iostream>
using namespace std;
// 在多态中通常基类中虚函数的实现都是毫无意义的，主要是调用子函数内的重写内容
// 因此可以将虚函数改为纯虚函数
// 纯虚函数语法： virtual 返回值类型 函数名 (参数列表) = 0;
// 当类中有了纯虚函数 则类为抽象类
// 抽象类特点：
//  无法实例化对象
//  派生类必需重写抽象类中的纯虚函数 否则派生类也为抽象类

class Base {
    public:
        virtual void func() = 0;
};

class A:public Base {
    public:
        virtual void func() {
            cout << "rewrite" << endl;
        }
        
};
int main() {
    // 抽象类无法实例化
    // Base a;
    // new Base;
    // 未重写func时无法实例化
    // A a;
    // new A;
    // 重写后
    Base * aa = new A;
    aa -> func();
}
