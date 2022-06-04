/***
############################
# File Name: struct_nested.cpp
# Author : TyhiLa
# QQ : 3055255696
# Email:hoshimaemi@outlook.com
# Blog：Null
# Created Time: Fri 27 May 2022 05:13:08 PM CST
 **/

#include <iostream>
using namespace std;

struct student {
    string name;
    int age;
    int score;
};

// 老师结构体
struct teacher {
    int id;
    string name;
    int age;
    struct student stu;
};

int main() {
    teacher t;
    t.id = 1000;
    t.name = "na";
    t.age = 50;
    t.stu.age = 18;
    t.stu.name = "nn";
    t.stu.score = 60;
    cout << t.id << endl;
    return 0;
}
