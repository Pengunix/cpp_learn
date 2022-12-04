#include <iostream>
using namespace std;

// 多继承
class Base1 {
    public:
        Base1() {
            m_A = 1;
            m_P = 666;
        }
        int m_A;
        int m_P;
};
class Base2 {
    public:
        Base2() {
            m_B = 100;
            m_P = 888;
        }
        int m_B;
        int m_P;
};
class Son:public Base1, public Base2 {
    public:
        Son() {
            m_C = 300;
            m_D = 400;
        }
        int m_C;
        int m_D;
};
int main() {
    Son s;
    cout << sizeof(s) << endl;
    cout << s.m_A << endl;
    cout << s.Base1::m_P << endl;
    cout << s.Base2::m_P << endl;

}