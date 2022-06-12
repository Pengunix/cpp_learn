/***
############################
# File Name: reference.cpp
# Author : TyhiLa
# QQ : 3055255696
# Email:hoshimaemi@outlook.com
# Blog：Null
# Created Time: Tue 07 Jun 2022 04:19:17 PM CST
 **/
// 引用，通常是给变量起别名
// 也就是说，它是某个已存在变量的另一个名字。一旦把引用初始化为某个变量，就可以使用该引用名称或变量名称来指向变量。
// 引用很容易与指针混淆，它们之间有三个主要的不同：
//   不存在空引用。引用必须连接到一块合法的内存。
//   一旦引用被初始化为一个对象，就不能被指向到另一个对象。指针可以在任何时候指向到另一个对象。
//   引用必须在创建时被初始化。指针可以在任何时间被初始化。
//   没有指针的引用，也就是没有数组的引用
//   没有引用的引用
//   不要返回局部变量的引用
//   函数调用可以作为左值

// 引用的本质是指针常量
#include <iostream>

using namespace std;

// 地址传递 交换变量
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
// 引用传递
void swap_r(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}
/*
int& ref_return() {
    int n = 10;
    return n; // 不要返回局部变量的引用
}
*/
int& test2() {
    static int a = 10; //静态变量存在全局区，生命长,程序结束后释放
    return a;
}
// 常量引用： 修饰形参防止误操作
// 引用使用场景，通常来修饰形参
void show(const int &v) {
    cout << v << endl;
}

int main()
{
    // 声明简单的变量
    int i;
    double d;

    // 声明引用变量
    int& r = i;
    double& s = d;

    i = 5;
    cout << "Value of i : " << i << endl;
    cout << "Value of i reference : " << r << endl;

    d = 11.7;
    cout << "Value of d : " << d << endl;
    cout << "Value of d reference : " << s << endl;
    
    int a = 10;
    int b = 20;
    swap_r(a, b);
    cout << a << "  " << b << endl;

    // 函数调用可以作为左值
    // 自动转换为 int * const ref = &a;
    // 指针常量的指向不可改，也就说明了为什么引用不可修改
    int &ref = test2();
    cout << ref << endl;
    test2() = 1000; // 如果函数返回值是引用，则函数调用可以作为左值
    cout << ref << endl; // ref 是引用，自动转换为 *ref

    // 加上const 后 编译器将代码 改成 int temp = 10; const int &test = temp;
    const int &test = 10; // 引用必须引一块合法的内存空间
    cout << test << endl;
    return 0;
}
