/***
############################
# File Name: struct_pointer.cpp
# Author : TyhiLa
# QQ : 3055255696
# Email:hoshimaemi@outlook.com
# Blog：Null
# Created Time: Fri 27 May 2022 04:13:35 PM CST
 **/

#include <iostream>
using namespace std;

struct Student {
    string name;
    int age;
    int score;
};

int main() {
    // struct 关键字可省略
    // 创建学生结构体变量
    struct Student s1 = {"张三", 18, 100};
    // 指针指向
    struct Student * p = &s1;
    // 通过指针访问结构体变量的值
    cout << p -> name << endl;
}
void swap() {

}
