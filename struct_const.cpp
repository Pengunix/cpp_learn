/***
############################
# File Name: struct_const.cpp
# Author : TyhiLa
# QQ : 3055255696
# Email:hoshimaemi@outlook.com
# Blog：Null
# Created Time: Sun 05 Jun 2022 05:20:19 PM CST
 **/
// 用const来防止误操作
// const 使用场景
#include <iostream>
using namespace std;
struct student {
    string name;
    int age;
    int score;
};
// 值传递两个参数地址不同 此函数不会修改原数据
// 但此操作比较消耗内存 因为会复制一份变量
void printStudent(struct student s)
{
    cout << (int*)&s << endl;
    cout << s.name << s.score << s.age;
}
// 在此加入const修饰结构体
void printStudent2(const struct student* p)
{
    // 我们当然可以修改原变量内容
    // 但是 当我们不希望结构体被修改时 需要加const修饰
    // s->age = 110; 此操作会报错
    cout << p->name << p->score << p->age << endl;
    cout << (int*)p << endl;
}
int main()
{
    // 创建结构体变量
    struct student s = { "张三", 15, 70 };
    cout << (int*)&s << endl;
    // 通过函数来打印结构体变量信息
    printStudent(s);
    printStudent2(&s);
}
