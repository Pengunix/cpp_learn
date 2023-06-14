/***
############################
# File Name: stu_class.cpp
# Author : TyhiLa
# QQ : 3055255696
# Email:hoshimaemi@outlook.com
# Blog：Null
# Created Time: Sun 26 Jun 2022 07:01:42 PM CST
 **/

#include <iostream>
using namespace std;
// 学生类
class Student {
public: //公共权限
    // 类中的属性和行为，我们统一称为 成员
    // 属性 成员属性 成员变量
    // 行为 成员函数 成员方法
    string m_Name;
    int m_id;
    void showStudent() { cout << m_Name << m_id << endl; }
};
// 封装 访问权限
// public 公共权限 protected 保护权限 private 私有权限
// 类内类外都可 仅类内和子类 仅类内
class Person {
public:
    // 公共权限
    string m_Name;

protected:
    // 保护
    string m_Car;

private:
    // 私有
    int m_id;

public:
    void func()
    {
        m_Name = "zhangsan";
        m_Car = "tractor";
        m_id = 1111;
    }
};
// class 和 struc 区别
// struct 默认的访问权限是 公共 public
// class 默认权限是私有 private
class C1 {
    // 默认权限是私有
    int m_A;
};
struct C2 {
    int m_A;
};

int main()
{
    // 实例化
    Student s1;
    s1.m_Name = "sam";
    s1.m_id = 1;
    // 调用方法
    s1.showStudent();

    Person p1;
    p1.m_Name = "san";
    // p1.m_Car = "nnn"; 声明在保护中 报错
    // p1.m_id = 123 同样报错
    //C1 c1;
    // c1.m_A = 100;  报错 无法访问
    C2 c2;
    c2.m_A = 100;

}
