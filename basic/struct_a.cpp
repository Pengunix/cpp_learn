/***
############################
# File Name: struct_a.cpp
# Author : TyhiLa
# QQ : 3055255696
# Email:hoshimaemi@outlook.com
# Blog：Null
# Created Time: Fri 27 May 2022 12:16:38 PM CST
 **/

#include <iostream>
using namespace std;
// 1.创建结构体
struct Student {
    string name;
    int age;
    int score;
};

// 不建议使用，，
struct Colle {
    string name;
    int salary;
    int age;
} c1;
int main() {
    // 2.创建具体学生
    // struct 可以省略,定义时不可以省
    struct Student s1;
    s1.name = "张三";
    s1.age = 23;
    s1.score = 0;
    cout << s1.name << "  " << s1.age << "  " << s1.score << endl;
    struct Student s2 = {"里斯", 16, 100};
    cout << s2.name << s2.age << s2.score << endl;
    c1 = {"jhon", 15000, 100};
    cout << c1.name << c1.salary << c1.age << endl;
    return 0;
}

