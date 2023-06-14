#include <iostream>
using namespace std;

// 当子类与父类出现同名的成员，如何通过子类对象访问父类同名数据
//  访问子类同名成员，直接访问即可
//  访问父类同名成员，需要加作用域
class Base {
    public:
        Base () {
            m_A = 1;
        }
        int m_A;
        static int m_SA;
        void func() {
            cout << "func in Base" << endl;
        }
        void func(int a) {
            cout << "func in Base with arg a " << a << endl;
        }
        static void static_func() {
            cout << "static fun in Base" << endl;
        }
};
int Base::m_SA = 100;

class Son :public Base {
    public:
        Son() {
            m_A = 200;
        }
        int m_A;
        static int m_SA;
        void func() {
            cout << "func in Son" << endl;
        }
        static void static_func() {
            cout << "static fun in Son" << endl;
        }
};
int Son::m_SA = 123;

int main() {
    Son s;
    cout << s.m_A << endl;
    cout << s.m_SA << endl;
    cout << Son::m_SA << endl;
    // 通过作用域访问父类属性
    cout << s.Base::m_A << endl;
    cout << s.Base::m_SA << endl;
    cout << Base::m_SA << endl;
    // 通过子类访问父类中的静态属性
    cout << Son::Base::m_SA << endl;
    // 成员函数同理
    s.func();
    s.Base::func();
    s.Base::func(2);
    // 静态成员函数也同理
    s.static_func();
    s.Base::static_func();
    
    Son::static_func();
    Son::Base::static_func();
    return 0;
}