#include <iostream>
#include <string>
using namespace std;

// 类模板成员函数的类外实现
template<class T1, class T2>
class Person {
  public:
    Person(T1 name, T2 age);
    void showPerson();

    T1 m_name;
    T2 m_age;
};

template<class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age) {
  this->m_name = name;
  this->m_age = age;
}
template<class T1, class T2>
void Person<T1, T2>::showPerson() {
  cout << this->m_name << " " << this->m_age << endl;
}

int main() {
  Person<string, int> p("33", 4);
  p.showPerson();
}
