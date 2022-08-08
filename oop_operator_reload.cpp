/***
############################
# File Name: oop_operator_reload.cpp
# Author : TyhiLa
# QQ : 3055255696
# Email:hoshimaemi@outlook.com
# Blog：Null
# Created Time: Mon 08 Aug 2022 08:12:35 AM CST
 **/
// 运算符重载：对已有的运算符进行重定义，赋予其另一种功能，以适应不同的数据类型
// 内置的数据类型运算符不可重载
// 不要滥用运算符重载
#include <iostream>
#include <iterator>
using namespace std;
// 成员函数重载
class Person {
    public:
        Person(int a, int b): m_A(a), m_B(b) {
        }
        /*
        Person operator+(Person &p){
            Person temp(this->m_A + p.m_A, this->m_B + p.m_B);
            return temp;
        }
        */
        int m_A;
        int m_B;


};
// 全局函数重载
Person operator+(const Person &p1, const Person &p2) {
    Person temp(p1.m_A+p2.m_A, p1.m_B + p2.m_B);
    return temp;
}
// 函数重载
Person operator+(const Person &p1, int num) {
    Person temp(p1.m_A+num, p1.m_B + num);
    return temp;
}
void test() {
    Person p1(10, 10);
    Person p2(10, 10);

    // 成员函数重载的本质
    // Person p3 = p1.operator+(p2);
    // Person p3 = p1 + p2;
    // 全局函数重载的本质
    // Person p3 = operator+(p1, p2);
    Person p3 = p1 + p2;
    // 运算符重载也可以发生函数重载
    // 例如
    Person p4 = p1 + 100;     // Person + int
    cout << p3.m_A << "  " << p3.m_B << endl;
    cout << p4.m_A << "  " << p4.m_B << endl;

}
int main() {
    test();
}
