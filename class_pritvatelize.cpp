/***
############################
# File Name: class_pritvatelize.cpp
# Author : TyhiLa
# QQ : 3055255696
# Email:hoshimaemi@outlook.com
# Blog：Null
# Created Time: Mon 27 Jun 2022 09:04:53 AM CST
 **/
// 私有化成员 
// 可以自己控制读写权限
// 对于写可以检测数据的有效性
#include <iostream>
using namespace std;


class Person {
// 设置私有后 同时设置访问数据的接口
public:
    // 设置姓名
    void setName(string name) {
        m_Name = name;
    }
    // 获取姓名
    string getName(){
        return m_Name;
    }
    // 获取年龄
    int getAge() {
        m_Age = 0;
        return m_Age;
    }
    void setAge(int age){
        if (age < 0 || age > 150) {
            m_Age = 0;
            return;
        }
        m_Age = age;

    }
    void set_id(int id){
        m_Id = id;
    }

private: 
    // 设置读写权限
    string m_Name;
    // 设置只读权限
    int m_Age;
    // 设置只写权限
    int m_Id;
    
};
int main() {
    Person p;
    // p.m_Name = "san";
    p.setName("zhangsan");
    cout << p.getName() << endl;
    cout << p.getAge() << endl;
    p.set_id(123);
    return 0;
}
