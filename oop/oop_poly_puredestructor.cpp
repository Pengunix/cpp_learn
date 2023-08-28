/***
############################
# File Name: oop_poly_puredestructor.cpp
# Author : TyhiLa
# QQ : 3055255696
# Email:hoshimaemi@outlook.com
# Blog：Null
# Created Time: Wed 14 Dec 2022 07:10:52 AM CST
 **/
// 多态使用时，如果子类中有属性要开辟到堆区，那么父类指针在释放时无法调用子类的析构代码
// 解决：将父类的析构函数改为虚析构或者纯虚析构
// 虚析构和纯虚析构 
//  解决父类指针释放子类对象
//  都需要有具体的函数实现
// 区别
//  如果是纯虚析构，该类属于抽象类，无法实例化对象
#include <iostream>
using namespace std;

class Base {
    public:
        Base() {
            cout << "Base constructor" << endl;
        }
        // 改为虚析构
        //virtual ~Base() {
        //    cout << "Base destructor" << endl;
        //}
        virtual void func() = 0;
        // 使用纯虚析构 也需要类外实现
        virtual ~Base() = 0;
}; 
Base::~Base() {

}

class Derived:public Base {
    public:
        Derived() {
            cout << "Derived constructor" << endl;
            m_A = new string("堆区数据");
        }
        ~Derived() {
            cout << "Derived destructor" << endl;
            if (m_A != NULL) {
                delete m_A;
            }
            m_A = NULL;
        }
        virtual void func() {
            cout << *m_A << "test" << endl;
        }
        string * m_A;
};
int main() {
    Base * d = new Derived;
    d->func();
    //父类指针调用父类析构 使用虚析构解决
    delete d;
}
