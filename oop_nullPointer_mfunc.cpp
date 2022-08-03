/***
############################
# File Name: oop_nullPointer_mfunc.cpp
# Author : TyhiLa
# QQ : 3055255696
# Email:hoshimaemi@outlook.com
# Blog：Null
# Created Time: Tue 02 Aug 2022 09:48:42 PM CST
 **/
// c++ 中空指针也可访问成员函数，但要注意有没有用到this指针
// 如果用到this指针需要判断代码的健壮性
#include <cstddef>
#include <iostream>
using namespace std;
class Person {
   public:
    void showClassName() { cout << "Person class" << endl; }
    void showPersonAge() {
        // 等价于 this -> m_Age
        // 报错是因为传入的指针为空
        // 解决
        if (this == NULL) {
            return;
        }
        cout << m_Age << endl;
    }
    int m_Age;
};
void test() {
    Person *p = NULL;
    p->showClassName();
    // this is nullptr
    // p->showPersonAge();

}
int main() {
    test();
    return 0;
}
