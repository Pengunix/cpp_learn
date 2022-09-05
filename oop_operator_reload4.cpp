/***
############################
# File Name: oop_operator_reload4.cpp
# Author : TyhiLa
# QQ : 3055255696
# Email:hoshimaemi@outlook.com
# Blog：Null
# Created Time: Sun 04 Sep 2022 02:17:32 PM CST
 **/
// 关系运算符重载
#include <iostream>
using namespace std;

class Person {
public:
    Person(string name, int age): m_name(name), m_age(age) {}

    bool operator== (Person &i) {
        if (m_name == i.m_name && m_age == i.m_age) {
            return true;
        }
        else {
            return false;
        }
    }
    string m_name;
    int m_age;
};
void test() {
    Person p1("Tom", 18);
    Person p2("Tom", 18);
    if (p1==p2) {
        cout << true << endl;
    }
}
int main() {
    test();
}
