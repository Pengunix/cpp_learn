/***
############################
# File Name: bubble_sort_func_p.cpp
# Author : TyhiLa
# QQ : 3055255696
# Email:hoshimaemi@outlook.com
# Blog：Null
# Created Time: Fri 27 May 2022 09:42:59 AM CST
 **/

#include <iostream>
using namespace std;
// int arr[] 也可以换成 int * arr 由于不能拷贝数组所以不能值传递
// 数组会被转为指针 传递的参数就是指向数组首元素的指针
void Bsort(int arr[], int len) {
    for (int i=0;i<len-1;i++) {
        for (int j=0;j<len-i-1;j++)
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
    }
}
int main() {
    int arr[10] = {1,3, 5, 2, 7, 8, 4, 9, 0};
    // sizeof 务必注意数组中元素大小!!
    Bsort(arr, sizeof(arr)/4);
    for (int& i: arr) {
        cout << i << endl;
    }
    return 0;
}
