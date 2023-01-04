/***
############################
# File Name: oop_const_func.cpp
# Author : TyhiLa
# QQ : 3055255696
# Email:hoshimaemi@outlook.com
# Blog：Null
# Created Time: Wed 03 Aug 2022 10:12:11 PM CST
 **/
// 常函数
//  成员函数加const后称其为常函数
//  常函数不可以修改成员属性
//  成员属性声明时加关键字mutable后 在常函数中依然可以修改
// 常对象
//  声明对象前加const称该对象为常对象
//  常对象只能调用常函数
#include <iostream>
using namespace std;
class Person {
    public:
        // this指针是一个指针常量 指针的指向是不可修改的
        // Person * const this;
        // const Person * const this; // 指向的值也不可修改
        // 在成员函数后面加const 是修饰this指向，让指针指向的值也不可修改
        void showPerson () const {
            // m_A 不可被修改
            //this->m_A = 100;
            // 不可改变指向
            // this = NULL;
            // m_B mutable
            this -> m_B = 10;
        }
        void func() {
            m_A = 100;

        }
        int m_A;
        mutable int m_B; // 可变变量 在常函数中也可修改 加mutable
};
void test() {
    Person p;
    p.showPerson();
}
void test1() {
    const Person p; // 常对象
    // p.m_A = 100; 不可修改
    p.m_B = 10; // mutable在常对象中可修改
    // 常对象只能调用常函数
    p.showPerson();
    // p.func(); 函数没有被标记为const 不可调用 常对象不可调用普通成员函数
    // 因为普通成员函数可以修改属性
    // 常对象可以修改静态变量的值

}
int main() {
}
