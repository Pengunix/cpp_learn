/***
############################
# File Name: Deep_shallow_copy.cpp
# Author : TyhiLa
# QQ : 3055255696
# Email:hoshimaemi@outlook.com
# Blog：Null
# Created Time: Sun 17 Jul 2022 09:12:48 PM CST
 **/
// 浅拷贝： 简单的赋值拷贝操作
// 深拷贝： 在堆区重新申请空间，进行拷贝操作
// 总结：如果属性有在堆区开辟的，一定要自己提供拷贝构造函数，防止浅拷贝带来问题
#include <cstddef>
#include <iostream>
using namespace std;
class Person {
   public:
    Person(int age, int height) {
        cout << "有参构造函数" << endl;
        m_age = age;
        m_height = new int(height);
    }
    // 解决 写一个拷贝构造函数
    Person(const Person &p) {
        cout << "拷贝函数" << endl;
        // 修改之前编译器提供的代码
        m_age = p.m_age;
        // m_height = p.m_height;
        m_height = new int(*p.m_height);
    }
    ~Person() {
        cout << "析构函数" << endl;
        // 析构销毁堆区数据
        if (m_height != NULL) {
            // 删除变量
            delete m_height;
            // 指针置空 防止野指针
            m_height = NULL;
        }
    }
    int m_age;
    int* m_height;
};
void test() {
    Person p1(10, 180);
    cout << "p1 age " << p1.m_age << "p1 height " << *p1.m_height << endl;
    // 编译器提供了我没有写的拷贝函数，并进行了浅拷贝操作
    //              报错 如果使用了编译器提供的拷贝函数，会做浅拷贝操作
    //              释放顺序是先p2后p1，释放了堆区内存，但p1的m_height
    //              仍然保存了堆区数据的地址，导致一块内存被重复释放
    //              所以浅拷贝带来的问题就是堆区内存的重复释放
    //              可以用深拷贝来解决
    //              创建新的一个堆区数据，每个对象中的m_height 保存不同的地址
    //              避免重复释放内存
    Person p2(p1);
    // cout << "p2 age " << p2.m_age << endl;
    cout << "p2 age " << p2.m_age << "p2 height " << *p2.m_height << endl;
}
int main() {
    test();
    return 0;
}
