/***
############################
# File Name: whentouseCopy.cpp
# Author : TyhiLa
# QQ : 3055255696
# Email:hoshimaemi@outlook.com
# Blog：Null
# Created Time: Sat 16 Jul 2022 05:47:08 PM CST
 **/
// 拷贝构造函数调用时机主要三种情况
// 使用一个已经创建好的对象来初始化一个新对象
// 值传递的方式给函数传值
// 以值方式返回局部对象
#include <iostream>
using namespace std;

class Person {
public:
    Person() { cout << "默认构造函数" << endl; }
    Person(int age)
    {
        m_age = age;
        cout << "有参构造函数" << endl;
    }
    Person(const Person& p)
    {
        m_age = p.m_age;
        cout << "拷贝构造函数" << endl;
    }
    ~Person() { cout << "默认析构函数" << endl; }
    int m_age;
};
// 初始化一个新对象
void test01()
{
    Person p1(20);
    Person p2(p1);
    cout << p2.m_age << endl;
}
// 值转递一个对象
void do_some(Person p) { }
void test02()
{
    Person p;
    // 实参在传给形参时 会复制一份 调用拷贝构造 隐式转换
    do_some(p);
}
// 值方式返回局部对象
Person do_more()
{
    Person p1;
    // 因为返回的是值 会创建一份新的变量 返回给test03
    // 编译器更新 copy epilision 不能复现
    cout << (int*)&p1 << endl;
    return p1;
}
void test03() { 
    Person p = do_more();
    cout << (int*)&p << endl;
}
int main()
{
    test03();
    return 0;
}
