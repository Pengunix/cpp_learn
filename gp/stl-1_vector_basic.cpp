#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void myPrint(int val) {
  cout << val << endl;
}

class Person {
public:
  Person(string name, int age) {
    this->m_Name = name;
    this->m_Age = age;
  }
  string m_Name;
  int m_Age;
};

void test1() {
  // vector<int> v1 = {1, 2, 3, 4, 5, 4};
  vector<int> v;
  for (int i=0;i<10;i++) {
    v.push_back(i);
  }
  vector<int>::iterator itBegin = v.begin(); // 指向容器第一个元素
  vector<int>::iterator itEnd = v.end(); // 指向容器最后一个元素的下一个位置
  // 第一种迭代方式
  // while (itBegin != itEnd) {
  //   cout << *itBegin << endl;
  //   itBegin++;
  // }
  // 第二种
  // for (auto &i : v) {
  //   cout << i << endl;
  // }
  // 第三种
  // for (vector<int>::iterator it = v.begin();it!=v.end();it++) {
  //   cout << *it << endl;
  // }
  // 第四种
  for_each(v.begin(), v.end(), myPrint);
}

void test2() {
  vector<Person> v;
  Person p1("aaa", 10);
  Person p2("aaa", 11);
  Person p3("aaa", 12);
  Person p4("aaa", 13);
  Person p5("aaa", 14);

  v.push_back(p1);
  v.push_back(p2);
  v.push_back(p3);
  v.push_back(p4);
  v.push_back(p5);

  for (Person &i: v) {
    cout << i.m_Age << "  " << i.m_Name << endl;
  }
}

void test3() {
  vector<vector<int>> v;

  // 创建小容器
  vector<int> v1;
  vector<int> v2;
  vector<int> v3;
  vector<int> v4;

  // 向小容器添加数据
  for (int i=0;i<4;i++) {
    v1.push_back(i + 1);
    v2.push_back(i + 2);
    v3.push_back(i + 3);
    v4.push_back(i + 4);
  }

  // 小容器插入大容器
  v.push_back(v1);
  v.push_back(v2);
  v.push_back(v3);
  v.push_back(v4);

  // 遍历数据
  for (vector<int> &i: v) {
    for (int &j: i) {
      cout << j << endl;
    }
  }
  
}

int main() {
  // test1();
  // test2();
  test3();
  return 0;
}
