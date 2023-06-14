/***
############################
# File Name: oop_static_member.cpp
# Author : TyhiLa
# QQ : 3055255696
# Email:hoshimaemi@outlook.com
# Blog：Null
# Created Time: Sat 30 Jul 2022 10:09:27 PM CST
 **/
// 静态成员
// 静态成员就是在成员变量和成员函数前加上关键字static，称为静态成员
// 静态成员分为
//  静态成员变量
//      所有对象共享一份数据
//      编译阶段分配内存 全局区
//      类内声明 类外初始化
//  静态成员函数
//      所有对象共享同一个函数
//      静态成员函数只能访问静态成员变量
#include <iostream>
using namespace std;
class Person {
    public:
        // 所有对象共享
        // 编译阶段分配内存
        // 类内声明 类外初始化
        static int m_A;
        // 静态成员变量也有访问权限
        
        // 静态成员函数
        // 所有对象共享同一个函数
        // 只能访问静态成员变量
        int m_C;
        static void func() {
            m_A = 100; // 静态成员函数可以访问静态成员变量
            // m_C = 100; 报错 静态成员函数不可以访问非静态成员变量
            // 因为多个对象不能共享一份数据
            cout << "func调用" << endl;

        }
        // 
        // 静态成员函数同样有访问权限
    private:
        static int m_B;
        static void func1() {
            cout << "静态私有成员函数" << endl;
        }
};
// 类外初始化 Person作用域
int Person::m_A = 100;
int Person::m_B = 600;

void test() {
    Person p;
    cout << p.m_A << endl;
    Person p1;
    p1.m_A = 200;
    cout << p.m_A << endl;
}
void test1() {
    // 静态成员变量，不属于某个对象，所有对象都共享同一份数据。
    // 因此静态成员变量有两种访问方式
    // 1. 通过对象进行访问
    Person p;
    cout << p.m_A << endl;
    // 2. 通过类名进行访问
    cout << Person::m_A << endl;
    // 以下行报错 
    // cout << Person::m_B << endl;
}
void test2() {

    // 1. 通过对象进行访问
    Person p;
    p.func();
    // 2. 通过类名进行访问
    Person::func();
    // 错误 不能访问私有静态成员函数
    // Person::func1();

}
int main() {
    //test();
    //test1();
    test2();
}
