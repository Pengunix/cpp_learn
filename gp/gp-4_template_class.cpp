#include <iostream>
#include <string>
using namespace std;
// 建立一个通用的类，类中的成员 数据类型可以不具体指定，用一个虚拟的类型来代表
// 与函数模板的区别：
//  类模板没有自动类型推导的使用方式
//  类模板在模板参数列表中可以有默认参数
//  默认参数可以隐式类型转换 char -> int
// template<class NameType, class AgeType>
template<class NameType, class AgeType=int>
class Person {
  public:
    // Person<class NameType, class AgeType>
    Person(NameType name, AgeType age){
      this->m_name = name;
      this->m_age =age;
    }
    // 类模板中的成员函数在调用时创建 （没传类型）
    void showPerson() {
      cout << this->m_name << this->m_age << endl;
    }
    NameType m_name;
    AgeType m_age;
};

class Person1 {
  public:
    void showPerson1() {
      
    }
};

template<class T>
class MyClass {
  public:
    T obj;
    // 编译可过 成员函数未创建
    void func1() {
      obj.showPerson();
    }
    void func2() {
      obj.showPerson1();
    }
};

int main() {
  Person<string, int> p1("aa", 12);
  // Person p("aa", 12);不能自动类型推导
  // 使用默认参数
  Person<string> p("bb", 2);
  p1.showPerson();

  MyClass<Person1> m;
  // m.func1()报错 无 showPerson 函数 
  m.func2();
}
