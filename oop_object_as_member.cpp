/***
############################
# File Name: oop_object_as_member.cpp
# Author : TyhiLa
# QQ : 3055255696
# Email:hoshimaemi@outlook.com
# Blog：Null
# Created Time: Wed 27 Jul 2022 10:11:00 PM CST
 **/
// C++ 中类的成员可以是另一个类的对象，称该成员为对象成员
#include <iostream>
using namespace std;
class A {
   public:
    A() { cout << "Constructor of A" << endl; }
    ~A() { cout << "Decon of A" << endl; }
};

class B {
   public:
    A a;
    B() { cout << "Constructor of B" << endl; }
    ~B() {
        cout << "Decon of B" << endl;
    }
};
int main() { B b; }
