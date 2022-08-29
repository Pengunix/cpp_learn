/***
############################
# File Name: oop_operator_reload2.cpp
# Author : TyhiLa
# QQ : 3055255696
# Email:hoshimaemi@outlook.com
# Blog：Null
# Created Time: Mon 22 Aug 2022 10:20:14 PM CST
 **/
// 递增运算符重载
#include <iostream>
using namespace std;
class MyInteger {
    friend ostream& operator<< (ostream& cout, MyInteger i); 
    public:
        MyInteger() {
            m_Num = 0;
        }
        // 重载 ++myin 运算符 返回自身引用是为了可以连续自增
       MyInteger& operator++ () {
            m_Num++;
            // 下方重载了左移运算符 返回自身即可
            return *this;
        }

        // 重载 myint ++ 运算符
        // 在此定义 发生重定义 因为返回值不可作为重载的条件
        // 占位参数用于区分前置和后置递增
        // 返回值！！不能返回局部变量的引用
       MyInteger operator++(int) {
           // 记录 初始结果
            MyInteger temp = *this;
            // 加一
            m_Num++;
            // 返回初始结果
            return temp;
       }
    private:
        int m_Num;
};
// MyInteger 不用引用 后置++运算的是局部变量 结束就会被释放 引用指向空内存
ostream& operator<< (ostream& cout, MyInteger i) {
    cout << i.m_Num;
    return cout;
}
void test() {
    MyInteger myint;
    // 为了让cout 在左侧只能写全局函数
    cout << ++(++myint) << endl;
    // 如果 operator++ 返回的是值 则以下打印1 第一次增加后拷贝了一个对象
    // 对拷贝的对象进行了自增操作 myint 仍为1
    cout << myint << endl;
}

void test1() {
    MyInteger myint;
    myint++;
    cout << myint << endl;


}
int main() {
    //test();
    test1();
    /*
    int a = 0;
    // 由此可见为了让myinteger 达到与下方相同的效果
    // 需要返回引用而不是拷贝后的值
    cout << ++(++a) << endl;
    cout << a << endl;
    */
    return 0;
}
