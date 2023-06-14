/***
############################
# File Name: struct_exercise1.cpp
# Author : TyhiLa
# QQ : 3055255696
# Email:hoshimaemi@outlook.com
# Blog：Null
# Created Time: Mon 06 Jun 2022 02:26:28 PM CST
 **/

#include <iostream>
using namespace std;
struct Hero {
    string name;
    int age;
    string sex;
};
int main()
{
    struct Hero heros[] = { { "刘备", 23, "男" }, { "关羽", 22, "男" },
        { "张飞", 21, "男" }, { "赵云", 20, "男" }, { "貂蝉", 19, "女" } };
    for (int i=0;i<4;i++) {
        for (int j=0;j<5-i-1;j++) {
            if (heros[j].age > heros[j+1].age) {
                struct Hero temp = heros[j];
                heros[j] = heros[j+1];
                heros[j+1] = temp;
            }
        }
    }
    for (struct Hero &m : heros) {
        cout << m.name << m.age << m.sex << endl;
    }
    return 0;
}
