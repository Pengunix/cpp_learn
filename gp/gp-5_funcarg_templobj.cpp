#include <iostream>
using namespace std;

// 类模板对象做函数参数
// 三种传入方式
//  1. 指定传入类型  --直接显式指定对象的数据类型
//  2. 参数模板化    --将对象中的参数变为模板进行传递
//  3. 整个类模板化  --将对象类型 模板化进行传递

template<class T1, class T2>
class Person {
public:
  Person(T1 name, T2 age) {
    this->name = name;
    this->age = age;
  }
  void Print() {
    cout << this->name << " " << this->age << endl;
  }
  T1 name;
  T2 age;
};


//  1. 指定传入类型  --直接显式指定对象的数据类型
void showPerson(Person<string, int> &p) {
  p.Print();
}

void test1() {
  Person<string, int> p("bb", 10);
  showPerson(p);
}

//  2. 参数模板化    --将对象中的参数变为模板进行传递
template<class T1, class T2>
void showPerson1(Person<T1, T2> &p) {
  p.Print();
  cout << typeid(T1).name() << endl;
  cout << typeid(T2).name() << endl;
}
void test2() {
  Person<string, int> p("22", 10);
  showPerson1(p);
}

//  3. 整个类模板化  --将对象类型 模板化进行传递
template<class T>
void showPerson2(T &p) {
  p.Print();
  cout << typeid(p).name() << endl;
}

void test3() {
  Person<string, int> p("33", 10);
  showPerson2(p);
}

int main() {
  //test1();
  //test2();
  test3();
  return 0;
}
