/***
############################
# File Name: oop_inheritance.cpp
# Author : TyhiLa
# QQ : 3055255696
# Email:hoshimaemi@outlook.com
# Blog：Null
# Created Time: Mon 05 Sep 2022 06:50:10 PM CST
 **/
// 继承 三大oop特性之一
// 继承方式 公共继承 保护继承 私有继承
// 公有继承继承了父类的公有和保护 不可访问私有 继承后成员权限不变
// 保护继承同样继承父类的公有和保护 继承后成员按照保护处理
// 私有继承同理
#include <iostream>
using namespace std;

class A {
    public:
        A() {
            a = 10;
            b = 23;
            pro = 1;
            pri = 1;
        }
        int a;
        int b;
    protected:
        int pro;
    private:
        int pri;
};
// 默认公有
// class B: public A
class B : public A {
    public:
        void print() {
            cout << a << endl;
            cout << b << endl;
            cout << pro << endl;
        }

};

class C: protected A {
    public:
        void print() {
            cout << pro << endl;
        }
};
/*
class D: private A {
    public:
        void print() {
            cout << pri << endl
        }
};
*/

int main() {
    B b;
    b.print();

    C c;
    c.print();
    
}
