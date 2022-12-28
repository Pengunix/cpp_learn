/***
############################
# File Name: io-2_readfile.cpp
# Author : TyhiLa
# QQ : 3055255696
# Email:hoshimaemi@outlook.com
# Blog：Null
# Created Time: Wed 28 Dec 2022 12:19:23 PM CST
 **/
// 1.头文件
//  #include <fstream>
// 2.创建流对象
//  ifstream ifs;
// 3.打开文件
//  ifs.open("/path/to/file", 方式)
// 4.读数据
// 5.关闭文件
//  ifs.close()
#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream ifs;
    ifs.open("file/test", ios::in);
    if (!ifs.is_open()) {
        cout << "失败" << endl;
        return 0;
    }
    // 第一种读取方式
    /*
    char buf[1024] = {0};
    while (ifs >> buf) {
        cout << buf << endl;
    }
    */
    // 第二种
    /*
    char buf[1024] = {0};
    while (ifs.getline(buf, 1024)) {
        cout << buf << endl;
    }
    */
    // 第三种
    /*
    string buf;
    while (getline(ifs, buf)) {
        cout << buf << endl;
    }
    */
    // 第四种
    char c;
    while ((c = ifs.get()) != EOF) {
        cout << c;
    }

    ifs.close();
}
