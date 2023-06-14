/***
############################
# File Name: struct_exercise.cpp
# Author : TyhiLa
# QQ : 3055255696
# Email:hoshimaemi@outlook.com
# Blog：Null
# Created Time: Sun 05 Jun 2022 05:38:06 PM CST
 **/
// 案例描述
// 设计老师和学生的结构体，其中在老师的结构体当中，有老师姓名和一个存放五名学生的数组作为成员
// 学生的成员有姓名、考试分数、创建数组存放三名老师，通过函数给每个老师及所带的学生赋值
// 最终打印出老师数据以及老师所带学生的数据
#include <iostream>
#include <memory>
#include <ctime>
using namespace std;
struct Student {
    string name;
    int score;
};
struct Teacher {
    string name;
    struct Student stu_array[5];
};
// 给老师和学生赋值
void allocateSpace(struct Teacher tarray[], int len)
{
    string nameSeed = "ABCDE";
    for (int i = 0; i < len; i++) {
        tarray[i].name = "Teacher_";
        tarray[i].name += nameSeed[i];
        // 循环给每个学生命名
        for (int j = 0; j < 5; j++) {
            tarray[i].stu_array[j].name = "Student_";
            tarray[i].stu_array[j].name += nameSeed[j];
            int random = rand() % 60 + 40; // 取随机数 40 ~ 99
            tarray[i].stu_array[j].score = random;
        }
    }
}
void printInfo(struct Teacher tarray[], int len)
{
    for (int i = 0; i < len; i++) {
        cout << tarray[i].name << endl;
        for (int j = 0; j < 5; j++) {
            cout << tarray[i].stu_array[j].name
                 << "score: " << tarray[i].stu_array[j].score << endl;
        }
    }
}
int main()
{
    // 随机数种子
    srand((unsigned int)time(NULL));
    // 创建三名老师的数组
    struct Teacher tea_array[5];
    int len = sizeof(tea_array) / sizeof(tea_array[0]);
    // 通过函数给三个老师的信息赋值 给学生信息赋值
    allocateSpace(tea_array, len);
    // 打印所有老师及所带学生的信息
    printInfo(tea_array, len);
    return 0;
}
