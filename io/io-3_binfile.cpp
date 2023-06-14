/***
############################
# File Name: io-3_binfile.cpp
# Author : TyhiLa
# QQ : 3055255696
# Email:hoshimaemi@outlook.com
# Blog：Null
# Created Time: Wed 28 Dec 2022 02:15:50 PM CST
 **/

#include <iostream>
#include <fstream>
using namespace std;
// 二进制写文件
// 1.头文件
// 2.流对象
// 3.打开文件
// 4.写文件
// 5.关闭
class Person {
    public:
        char m_name[64];
        int m_age;
};
void test1() {
    ofstream ofs("file/person", ios::out | ios::binary);
    //ofs.open("file/person", ios::out | ios::binary);
    Person p = {"张三", 18};
    ofs.write((const char*)&p, sizeof(Person));

    ofs.close();
}

int main() {
    test1();
}
