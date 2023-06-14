/***
############################
# File Name: io-4_readbinfile.cpp
# Author : TyhiLa
# QQ : 3055255696
# Email:hoshimaemi@outlook.com
# Blog：Null
# Created Time: Wed 28 Dec 2022 02:31:06 PM CST
 **/

#include <iostream>
#include <fstream>
using namespace std;
// 二进制读文件
class Person {
    public:
        char m_name[64];
        int m_age;
};
void test1() {
    ifstream ifs("file/person", ios::in | ios::binary);
    if (!ifs.is_open()) {
        cout << "打开失败" << endl;
        return;
    }
    Person p;
    ifs.read((char*)&p, sizeof(Person));
    cout << p.m_name << endl;
    cout << p.m_age << endl;

    ifs.close();
}
int main() {
    test1();
}
