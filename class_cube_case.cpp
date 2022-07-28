/***
############################
# File Name: class_cube_case.cpp
# Author : TyhiLa
# QQ : 3055255696
# Email:hoshimaemi@outlook.com
# Blog：Null
# Created Time: Mon 27 Jun 2022 11:14:28 AM CST
 **/

#include <iostream>
using namespace std;

class Cube {
private:
    int c_lenth;
    int c_width;
    int c_height;

public:
    void setValue(int lenth, int width, int height)
    {
        if (lenth > 0 && height > 0 && width > 0) {
            c_lenth = lenth;
            c_height = height;
            c_width = width;
        } else {
            c_lenth = 0;
            c_height = 0;
            c_width = 0;
        }
    }
    int* getValue()
    {
        int* p = new int[3];
        // int *p = a;
        /*
        *p = c_width;
        //cout << (int*)p << endl;
        p++;
        *p = c_height;
        //cout << (int*)p << endl;
        p++;
        *p = c_lenth;
        //cout << (int*)p << endl;
        */
        /*
        c_width = 10;
        c_lenth = 10;
        c_height = 10;
        */
        // *p++ 先取 p所指空间的值 再指向下一个空间
        // *(p++) 先取值 再指向下一个空间 等同于 *p++
        // *++p先+1再取值
        // *(++p)等同与*++p 因为++ 与 * 优先级相同 从右边向左运算 上同
        // (*p)++ 先取内容 内容加一
        // ++(*p) 等同于 (*p)++
        *p = c_width;
        //cout << *p << " " << p << endl;
        *++p = c_lenth;
        //cout << *p << " " << p << endl;
        *++p = c_height;
        // cout << *p << " " << p << endl;
        // cout << (int*)p << endl;
        return p;
    }
    void cal_v()
    {
        int v = c_lenth * c_height * c_width;
        cout << v << endl;
    }
    void cal_bs()
    {
        int area = c_width * c_lenth;
        cout << area << endl;
    }
    /*bool isSame(Cube c1, Cube c2) {
       cout << endl;
    }*/
};

int main()
{
    Cube c1;
    c1.setValue(10, 10, 10);
    //c1.cal_v();
    //c1.cal_bs();
    int* p = c1.getValue();
    // cout << (int*)p << endl;
    for (int i = 0; i < 3; i++) {
        cout << *p << endl;
    }
    return 0;
}
