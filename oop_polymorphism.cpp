/***
############################
# File Name: oop_polymorphism.cpp
# Author : TyhiLa
# QQ : 3055255696
# Email:hoshimaemi@outlook.com
# Blog：Null
# Created Time: Fri Dec  9 17:48:13 2022
 **/
// 多态分为两类
//  静态多态： 函数重载 和 运算符重载属于静态多态复用函数名
//  动态多态：派生类和虚函数实现运行时多态
// 区别：
//  静态多态的函数地址早绑定-编译阶段确定函数地址
//  动态多态的函数地址晚绑定-运行阶段确定函数地址
#include <iostream>
using namespace std;
class Animal {
    public:
        // 在此加virtual 解决问题
        // 变为虚函数
        virtual void bark() {
            cout << "bark" << endl;
        }
};
// 动态多态满足条件
//  有继承关系
//  子类重写父类的虚函数
// 动态多态的使用
//  父类的指针或者引用 执行子类对象
class Cat:public  Animal {
    public:
        // 父类是虚函数 则子类自动为虚函数 virtual 可写可不写
        void bark() {
            cout << "meow" << endl;
        }
};
// Animal & animal = cat
void doBark(Animal &animal) {
    animal.bark();
}
int main() {
    // 父类引用接收子类对象
    // 此时执行父类函数
    // 函数地址早绑定 无论传什么对象都执行父类函数
    // 如果想执行子类的函数需要使用静态多态使地址晚绑定
    Cat cat;
    doBark(cat);

}
