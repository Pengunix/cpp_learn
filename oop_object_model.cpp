/***
############################
# File Name: oop_object_model.cpp
# Author : TyhiLa
# QQ : 3055255696
# Email:hoshimaemi@outlook.com
# Blog：Null
# Created Time: Sun 31 Jul 2022 09:37:01 PM CST
 **/
// 成员变量和成员函数分开存储
// 类内的成员变量和成员函数分开存储
// 只有非静态成员变量才属于类的对象上
#include <iostream>
using namespace std;
class Person {

};
class Person1 {
    int m_A;  // 非静态成员变量 属于类的对象上
    static int m_B; // 静态成员变量 不属于类对象上
    void func() {} // 非静态成员函数 不属于类对象上
    static void func1() {} // 静态成员函数 不属于类对象上
};
int Person1::m_B = 10;
void test() {
    Person p;
    // 空对象占用内存为1
    // c++ 编译器会给每个空对象也分配一个字节空间，是为了区分空对象内存地址
    // 每个空对象也应该有一个独一无二的内存地址
    cout << sizeof(p) << endl;

}
void test1() {
    Person1 p;
    // 占用 4
    // 增加静态成员变量后大小不变
    // 增加非静态成员函数 大小仍不变
    cout << sizeof(p) << endl;
    
}
int main() {
    // test();
    test1();
    return  0;
}
