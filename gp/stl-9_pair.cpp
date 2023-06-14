#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

// 对组：成对出现的数据，利用对组可以返回两个数据
// 创建方式
// pair<type, type> p(v1, v2);
// pair<type, type> make_pair(v1, v2);
int main() {
  pair<int, string> p(10, "Tom");

  cout << "Name: " << p.second << "Age: " << p.first << endl;
}
