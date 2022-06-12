/***
############################
# File Name: bubble_sort.cpp
# Author : TyhiLa
# QQ : 3055255696
# Email:hoshimaemi@outlook.com
# Blog：Null
# Created Time: Sun 22 May 2022 08:54:28 AM CST
 **/

#include <iostream>
using namespace std;
int main()
{
    int arr[9] = { 4, 3, 5, 6, 1, 7, 8, 9, 9 };
    int len = sizeof(arr) / 4;
    // 进行数组长度轮排序
    for (int i = 0; i < len - 1; i++) {
        // 对比次数减少
        for (int j = 0; j < len - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    for (int& a : arr) {
        cout << a << endl;
    }
    return 0;
}
