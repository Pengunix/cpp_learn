/***
############################
# File Name: oop_friend.cpp
# Author : TyhiLa
# QQ : 3055255696
# Email:hoshimaemi@outlook.com
# Blog：Null
# Created Time: Sat 06 Aug 2022 10:55:39 AM CST
 **/
// 在程序里
// 有些私有属性也想让类外特殊的一些函数或者类进行访问，就需要用到友元的技术
// 友元的目的是让一个函数或者类访问另一个类中的私有成员
// 友元的关键字为friend
// 友元的三种实现
//  全局函数做友元
//  类做友元
//  成员函数做友元
#include <iostream>
using namespace std;
class Building {
    // 友元 全局函数
    friend void someguy(Building *building);
    public:
        Building() {
            m_SettingRoom = "客厅";
            m_BedRoom = "卧室";
        }
        string m_SettingRoom;
    private:
        string m_BedRoom;
};
void someguy(Building *building) {
    cout << building->m_SettingRoom << endl;
    cout << building->m_BedRoom << endl;
}
int main() {
    Building mine;
    someguy(&mine);
    return 0;
}
