/***
    > File Name: for_iter.cpp
# File Name: for_iter.cpp
# Author : TyhiLa
# QQ : 3055255696
# Email:hoshimaemi@outlook.com
# Blog：Null
# Created Time: Fri 20 May 2022 08:24:02 AM CST
 **/

#include <iostream>
using namespace std;
int main() {
	int my_array[5] = {1, 2, 3, 4, 5};
	// 每个数组元素乘于 2
	for (int &x : my_array)
	{
	    x *= 2;
	    cout << x << endl;
	}
	// auto 类型也是 C++11 新标准中的，用来自动获取变量的类型
	for (auto &x : my_array) {
	    x *= 2;
	    cout << x << endl;
	}

	int arr[5] = { 1,2,3,4,5 };
	cout << "用值遍历" << endl;
	for (int i : arr)
	{
		cout << "arr地址：" << &arr << endl;
		cout << "第一次i的地址:" << &i << endl;
		break;
	}
	cout << "-----------------------------" << endl;
	cout << "用引用遍历" << endl;
	for (int& i:arr)
	{
		cout << "arr地址：" << &arr << endl;
		cout << "第一次i的地址:" << &i << endl;
		break;
	}
	cout << "Over" << endl;
    return 0;
}
