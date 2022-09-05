/***
############################
# File Name: oop_operator_reload3.cpp
# Author : TyhiLa
# QQ : 3055255696
# Email:hoshimaemi@outlook.com
# Blog：Null
# Created Time: Wed 31 Aug 2022 09:57:56 AM CST
 **/
// 赋值运算符重载
// 编译器至少给一个类添加4个函数
// 1. 默认无参构造函数
// 2. 默认无参析构函数
// 3. 默认拷贝构造函数 对属性进行值拷贝
// 4，赋值运算符 operato=, 对属性进行值拷贝
//如果有属性创建在堆区，做赋值时也会出现深浅拷贝的问题
#include <iostream>
using namespace std;

class Person {
public:
    Person (int age) {
        m_Age = new int(age);
    }
    int *m_Age;
    ~Person() {
        if (m_Age != NULL) {
            delete m_Age;
            m_Age = NULL;
        }
    }
    Person& operator=(Person &i) {
        if (m_Age != NULL) {
            delete m_Age;
            m_Age = NULL;
        }
        m_Age = new int(*i.m_Age);
        return *this;
    }
};

void test() {
    Person p1(18);
    Person p2(20);
    Person p3(11);
    p3 = p2 = p1;
    cout << *(p1.m_Age) << endl;
    cout << *(p2.m_Age) << endl;
}

int main() {
    test();
}
