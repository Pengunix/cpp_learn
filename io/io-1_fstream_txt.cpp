/***
############################
# File Name: io-1_fstream_txt.cpp
# Author : TyhiLa
# QQ : 3055255696
# Email:hoshimaemi@outlook.com
# Blog：Null
# Created Time: Fri 23 Dec 2022 04:40:47 PM CST
 **/
// 三个类
//  ofstream: 写操作
//  ifstream: 读取操作
//  fstream: 读写操作
// 1.写文件
//  头文件 fstream
// 2.流对象
//  ofstream ofs;
// 3.打开文件
//  ofs.open("/path/to/file", r/w)
// 4.写入数据
//  ofs << "data";
// 5.关闭文件
//  ofs.close();
#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ofstream ofs;
    ofs.open("file/test", ios::out);
    ofs << "asdfasdfasdf" << endl;
    ofs.close();
}
