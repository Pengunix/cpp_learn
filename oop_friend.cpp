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
// 前向声明 在定义之前只能使用该类的指针或引用
class Building;
class Pet {
    public:
        Pet();
        void visit();  // 可以访问Building私有成员
        void visit2(); // 不可访问
        Building * building;
};



class Building {
    // 友元 全局函数
    friend void someguy(Building *building);
    // 友元 类
    friend class Person;
    // 友元 成员函数 Pet类需要在 Building 之前进行定义
    friend void Pet::visit();
    public:
        // Building() {
        //     m_SettingRoom = "客厅";
        //     m_BedRoom = "卧室";
        // }
        // 类外写
        Building();
        string m_SettingRoom;
    private:
        string m_BedRoom;
};
// 类外的成员函数 
Building::Building() {
    m_SettingRoom = "客厅";
    m_BedRoom = "卧室";
}
// 因为 Pet 类需要声明Building类变量 所以Buildind类必须在Pet类之前声明 line21
// 因为Building 类的定义需要将Pet中的成员函数声明为友元 所以Building
// 必须在Pet类之后定义
// 因为Pet类中的构造函数需要调用Building 的构造函数
// 所以Pet类中的构造函数的实现必须在Building类定义之后
Pet::Pet() {
    building = new Building;
}
void Pet::visit() {
    cout << building->m_SettingRoom << endl;
    cout << building->m_BedRoom << endl;
}
void Pet::visit2() {
    cout << building->m_SettingRoom << endl;
    // 不能访问私有成员
}
class Person {
    public:
        // 访问Building中的公有和私有函数
        Person() {
            // 创建建筑物对象
            building = new Building;
        }
        void visit();
        Building * building;
};

void Person::visit() {
    cout << building->m_SettingRoom << endl;
    cout << building->m_BedRoom << endl;
}
void someguy(Building *building) {
    cout << building->m_SettingRoom << endl;
    cout << building->m_BedRoom << endl;
}
void test() {
    Person p;
    p.visit();
}
void test1() {
    Pet cat;
    cat.visit();
    cat.visit2();
}
int main() {
    //Building mine;
    //someguy(&mine);
    // test();
    test1();
    return 0;
}
