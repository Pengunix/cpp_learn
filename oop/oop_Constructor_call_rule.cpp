/***
############################
# File Name: Constructor_call_rule.cpp
# Author : TyhiLa
# QQ : 3055255696
# Email:hoshimaemi@outlook.com
# Blog：Null
# Created Time: Sun 17 Jul 2022 05:58:08 PM CST
 **/
// 默认情况下，c++编译器至少给类添加三个函数
// 1. 默认构造函数（无参，函数体为空）
// 2. 默认析构函数（无参，函数体为空）
// 3. 默认拷贝函数，对属性值进行拷贝
//
// 构造函数使用规则如下：
//  如果用户定义有参构造函数，c++不再提供默认构造，但是会提供默认拷贝构造
//  如果用户定义拷贝构造函数，c++不会再提供其他构造函数
#include <iostream>
using namespace std;
class Person {
public:
    Person() { cout << "person 默认构造函数" << endl; }
    Person(int age) {
        m_age = age;
        cout << "有参构造" << endl;
    }
// 注释后属性值不影响
//    Person(const Person &p) {
//        m_age = p.m_age;
//        cout << "拷贝构造" << endl;
//    }
    ~Person() { cout << "person 默认析构造函数" << endl; }
    int m_age;
};
void test() {
    Person p;
    p.m_age = 18;
    Person p2(p);
    cout << "p2   " << p2.m_age << endl;
}
//void test01() {
//    Person p; // 注释写的默认构造后 编译器同样不提供默认构造 所以会报错
//}
int main() {
    test();
}

