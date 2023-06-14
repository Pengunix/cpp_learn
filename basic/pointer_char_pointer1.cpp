/***
############################
# File Name: char_pointer1.cpp
# Author : TyhiLa
# QQ : 3055255696
# Email:hoshimaemi@outlook.com
# Blog：Null
# Created Time: Fri 20 May 2022 08:44:39 PM CST
 **/

#include <iostream>
using namespace std;
 
int main ()
{
   
    char name[] = "Zara Ali";
    cout << name << endl; // char[],输出整个字符数组的描述（就是字符串）
    cout << &name << endl; // char[],输出数组的地址（就是首字符的地址）
    cout << (void *)&name[1] << endl;//由于&name[1]的类型是char*,直接输出会是字符串，所以需要强转成其他类型才能输出地址
    printf("name:%s  name:%p  &name:%p &name[1]:%p\n",name,name,&name,&name[1]);//print可以指定输出样式，所以没有上面cout的问题
    
    cout << "********************" << endl;
    
    int bbb[] = {1,2,3,4};
    cout << bbb << endl;//int[],输出整个数组的描述（数组变量的地址代表整个变量的描述）
    cout << &bbb << endl;//int[],输出数组的地址（就是首元素的地址）
    cout << &bbb[1]<< endl;//&bbb[1] 输出下标为1的元素的地址（就是输出一个int *的指针变量的值）
 
   return 0;
}
