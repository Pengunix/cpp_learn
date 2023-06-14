#include <iostream>
using namespace std;

class Person {
  public:
    Person (string name, int age):m_age(age), m_name(name) {
      
    }
    int m_age;
    string m_name;
};
template <typename T>
bool Compare(T &a, T &b) {
  if (a == b) {
    return true;
  }
  return false;
}
template<> bool Compare(Person &p1, Person &p2) {
  if (p1.m_name == p2.m_name && p1.m_age == p2.m_age) {
    return true;
  }
  return false;
}


int main() {
  int a =10;
  int b = 20;

  Person p1("aa", 11);
  Person p2("bb", 12);

  // Compare(p1, p2);
  // 可使用运算符重载解决
  // 模板重载 具体化优先调用
  // 利用具体化的模板可以解决自定义类型的通用化
  // 学习模板并不是为了写模板，而是在STL能够运用系统提供的模板

  cout << Compare(p1, p2) << endl;
  cout << Compare(a, b) << endl;
}
