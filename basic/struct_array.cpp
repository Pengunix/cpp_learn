/***
############################
# File Name: struct_array.cpp
# Author : TyhiLa
# QQ : 3055255696
# Email:hoshimaemi@outlook.com
# Blog：Null
# Created Time: Fri 27 May 2022 03:54:30 PM CST
 **/

#include <iostream>
using namespace std;
struct Student {
    string name;
    int age;
    int score;
};
int main()
{
    // 结构体数组
    struct Student s1[]
        = { { "张三", 18, 80 }, { "里斯", 19, 80 }, { "散散", 19, 80 } };
    // 修改结构体数组中的值
    s1[2].name = "john";
    // 遍历结构体数组
    /*
    for (auto &i : s1) {
        cout << i.name << i.age << i.score << endl;
    }
    */
    for (int i = 0; i < 3; i++) {
        cout << "name " << s1[i].name << "  age " << s1[i].age << "  score "
             << s1[i].score << endl;
    }
    return 0;
}
