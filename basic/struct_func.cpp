/***
############################
# File Name: struct_func.cpp
# Author : TyhiLa
# QQ : 3055255696
# Email:hoshimaemi@outlook.com
# Blog：Null
# Created Time: Fri 27 May 2022 05:59:55 PM CST
 **/

#include <iostream>
#include <string>
using namespace std;
// 结构体做参数
// 结构体 值传递 地址传递
struct Student {
    string name;
    int age;
    int score;
};
// 打印学生信息
// 值传递
void printStudent(struct Student s) {
    // 修改参数
    s.age = 100;
    // 原变量函数没有变化
    // 打印内容出现变化
    cout << s.name << s.age << s.score << endl;
}
// 地址传递
void printStudent1(struct Student *p) {
    // main函数内出现变化
    p -> age = 200;
    cout << p -> name << p -> age << p -> score << endl;
}
int main() {
    // 结构体做函数参数
    // 将学生传入到一个参数中，打印学生身上的所有信息
    // 创建结构体变量
     struct Student s;
     s.name = "张三";
     s.age = 20;
     s.score = 85;
     printStudent(s);
     printStudent1(&s);
     cout << s.age << endl;
}
