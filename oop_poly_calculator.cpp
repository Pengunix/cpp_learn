/***
############################
# File Name: oop_poly_calculator.cpp
# Author : TyhiLa
# QQ : 3055255696
# Email:hoshimaemi@outlook.com
# Blog：Null
# Created Time: Sat 10 Dec 2022 09:10:48 PM CST
 **/

#include <iostream>
using namespace std;

class Calculator {
   public:
    int Action(string oper) {
        if (oper == "+") {
            return Num1 + Num2;
        } else if (oper == "-") {
            return Num1 + Num2;
        } else {
            return 0;
        }
    }
    // 如果要扩展以上函数 需要修改源码
    // 不符合开闭原则：对扩展进行开发 对修改进行关闭
    int Num1;
    int Num2;
};

void test1() {
    Calculator c;
    c.Num1 = 1;
    c.Num2 = 1;
    cout << c.Action("+") << endl;
}

// 利用多态实现计算器
// 先实现一个计算机基类(抽象类)
class AbstractCalculator {
   public:
    virtual int Action() { return 0; }
    int Num1;
    int Num2;
};
// 加法计算器类
class CalculatorAdd : public AbstractCalculator {
   public:
    virtual int Action() {
        return Num1 + Num2;
    }
};
// 减法计算器类
class CalculatorSub : public AbstractCalculator {
   public:
    virtual int Action() {
        return Num1 - Num2;
    }
};

void test2() {
    // 多态的使用条件
    // 基类的指针或引用指向子类的对象
    // 创建加法计算器对象 并将地址返回给抽象类指针
    AbstractCalculator * abc = new CalculatorAdd;
    abc -> Num1 = 10;
    abc -> Num2 = 10;
    cout << abc->Action() << endl;
    delete abc; 
    // 减法同理
    // 多态的好处：
    //  结构清晰可读性强
    //  增强代码的扩展性
    //  更容易维护
}
int main() {
    //test1();
    test2();
}
