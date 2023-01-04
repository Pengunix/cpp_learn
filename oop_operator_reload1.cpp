/***
############################
# File Name: oop_operator_reload1.cpp
# Author : TyhiLa
# QQ : 3055255696
# Email:hoshimaemi@outlook.com
# Blog：Null
# Created Time: Sun 21 Aug 2022 03:21:24 PM CST
 **/
// 左移运算符重载
#include <iostream>
#include <ostream>
using namespace std;
class Person {
    friend ostream & operator<<(ostream &out, Person &p);
    private:
        // 利用成员函数重载 p.operator<<(cout)    p << cout
        // 通常不利用成员函数重载左移运算符 无法实现cout 在左侧
        //void operator<<(cout) {
        //}
        int m_A;
        int m_B;
    public:
        Person(int a, int b) : m_A(a), m_B(b){

        }

};
// 利用全局函数重载  返回值为void无法链式输出endl
ostream & operator<<(ostream &out, Person &p) { // 本质opertor<< (cout, p)   cout << p
    cout << p.m_A << " " << p.m_B << endl;
    // 返回值为引用 链式调用参属和返回要相同
    return out;
}
void test() {
    Person p(10, 10);
    /*
    p.m_A = 10;
    p.m_B = 10;
    */
    // cout << p.m_A << "   " << p.m_B << endl;
    // cout << p;
    cout << p << endl;
}
int main() {
    test();
    return 0;
}
