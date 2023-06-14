/***
############################
# File Name: oop_init_array.cpp
# Author : TyhiLa
# QQ : 3055255696
# Email:hoshimaemi@outlook.com
# Blog：Null
# Created Time: Wed 27 Jul 2022 09:58:10 PM CST
 **/
// 初始化列表
#include <iostream>
using namespace std;
class Person {
public:
    // 传统初始化操作
        //Person(int a, int b, int c) {
        //    m_a = a;
        //    m_b = b;
        //    m_c = c;
        //} 
    // 初始化列表
    Person(int a, int b, int c): m_a(a), m_b(b), m_c(c) {

    }
    int m_a;
    int m_b;
    int m_c;


};
void test() {
    Person p(10, 20, 40);
    //Person p;
    cout << p.m_a << p.m_b << p.m_c << endl;
}
int main() {
    test();
}
