/***
############################
# File Name: classify_func.cpp
# Author : TyhiLa
# QQ : 3055255696
# Email:hoshimaemi@outlook.com
# Blog：Null
# Created Time: Sat 09 Jul 2022 07:24:31 PM CST
 **/
// 构造函数的分类和调用
// 两种分类方式
//  按参数分为： 有参构造和无参构造(默认构造)
//  按类型分为： 普通构造和拷贝构造
// 三种调用方式
//  括号法
//  显示法
//  隐式转换法

#include <iostream>
using namespace std;


class Person {
public:
    // 无参构造
    Person () {
        cout << "person 无参构造函数" << endl;
    }
    // 有参构造
    Person (int a) {
        age = a;
        cout << "person 有参构造函数" << endl;

    }
    // 拷贝构造 加const 关键字修饰 传入的对象不可变
    Person(const Person &p) {
        // 将传入的这个人身上的所有属性拷贝到新对象上
        cout << "person 拷贝构造函数" << endl;
        age = p.age;
        
    }
    int age;
    ~Person() {
        cout << "person 析构函数" << endl;
    }
};
// 调用
void test() {
    /*
    // 括号法
    Person p; // 默认构造函数调用
    Person p2(10);
    // cout << p2.age << endl;
    Person p3(p2);
    cout << p3.age << endl;
    // 注意
    // 调用默认构造函数时不要加() 
    // Person p1(); 没有创建出对象
    // 因为编译器会认为这行代码是函数的声明, 不会创建对象, 在函数体内部声明函数是允许的
    // 不要利用拷贝函数初始化匿名函数对象 编译器会认为Person (p3) 等价 
    // Person p3 编译器会认为这是一个对象的声明
    */
    // 显式法
    Person p1;
    // 调用有参构造
    Person p2 = Person(10);
    // 调用拷贝构造
    Person p3 = Person(p2);

    Person(10); // 匿名对象 创建了一个对象但没有名字 特点:
                // 当前行执行结束后，系统会立即回收掉匿名对象
    // Person(p3); 错误： Person p3 重定义
    
    // 隐式转换法
    Person p4 = 10; // 相当于 Person p4 = Person(10);有参构造
    Person p5 = p4; // 拷贝构造
}
int main() {
    // Person p;
    test();
    return 0;
}
