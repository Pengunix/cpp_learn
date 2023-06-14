/***
############################
# File Name: oop_this_pointer.cpp
# Author : TyhiLa
# QQ : 3055255696
# Email:hoshimaemi@outlook.com
# Blog：Null
# Created Time: Mon 01 Aug 2022 09:50:37 PM CST
 **/
// 每一个非静态成员函数只会产生一份函数实例，也就是多个同类型的对象会共用同一块代码
// 这一块代码时如何区分那个对象调用的呢？
// c++提供了特殊的对象指针，this，解决上述问题，this指向被调用的成员函数所需的对象
// this是隐含每一个非静态函成员函数内的一种指针
// this不需要定义，直接使用
// 用途：
//  当形参和成员变量同名时，可用this来区分
//  在类的非静态成员函数中返回对象本身，可用return *this
#include <iostream>
using namespace std;
// 解决名称冲突
class Person {
   public:
    Person(int age) {
        // 形参与以下两个变量是同一个变脸 故 test 中的测试为乱码
        // age = age;
        // 加入this 指向的是被调用的成员函数所属的对象
        this->age = age;
    }
    // 引用指向本身内存，不用引用就是拷贝 拷贝指向另一个内存
    // 如果不用引用的方式返回，相当于返回与p2不同的另一个Person （只是age都是20 ）那么后续的加年龄操作就与p2没关系了
    // 不返回引用就需要拷贝，那么p2在加了一次后
    // 以后的运算都是拷贝的p2参与，p2的值只改变一次
    Person& PersonAddAge(Person &p) {
        this->age += p.age; 
        // this指向p2 而*this 指向p2对象本体
        return *this;
    }
    int age;
};
void test() {
    Person p(19);
    cout << p.age << endl;
}
// 返回对象本身 用*this
void test1() {
    Person p1(14);
    Person p2(10);
    // 链式思想
    p1.PersonAddAge(p2).PersonAddAge(p2).PersonAddAge(p2);
    cout << p1.age << endl;
}
int main() { 
    // test(); 
    test1();
    return 0;
}
