#include <iostream>
using namespace std;

// 菱形继承
// 两子类继承同一个父类 又有一个类同时继承了上面两个子类
class A {
    public:
        int m_test;
        A() {
            m_test = 1;
        }
};
// 虚继承 A称为虚基类
class B :virtual public A {

};

class C :virtual public A {

};

class D : public B, public C {

};


int main() {
    D d;
    // 不明确
    // d.m_test = 111111;
    // ok
    d.B::m_test = 111;
    d.C::m_test = 222;
    // 同一个数据有两份 可用虚继承解决
    // 未使用虚继承时 111 222
    // 使用虚继承 222 222
    cout << d.B::m_test << endl;
    cout << d.C::m_test << endl;

    // 使用虚继承后 数据v只剩一份 以上两个修改数据的操作都作用在这一份数据上
    cout << d.m_test << endl;
    /*
       vbptr : 虚拟基类指针 virtual base pointer
       vbtable: 虚拟基类表 virtual base table
       D 类的vbptr指向 C D的 vbtable 表中分别记录了两份数据在连续内存中的偏移量
       偏移后的位置对应同一份m_test数据
       虚继承只继承指针
    */


}