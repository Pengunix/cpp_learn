#include <iostream>
using namespace std;

// 类模板配合友元函数的类内和类外实现
// 全局函数类内实现-直接在类内声明友元即可
// 全局函数类外实现-需前向声明<

// 两部分前向声明
template<class NameType, class AgeType>
class Person;

template<class NameType, class AgeType>
void printPerson1(Person<NameType, AgeType> p) {
  cout << p.m_name << "  " << p.m_age << endl;
}
// 结束

template<class NameType, class AgeType=int>
class Person {
  // 全局函数类内实现
  friend void printPerson(Person<NameType, AgeType> p) {
    cout << p.m_name << "  " << p.m_age << endl;
  }
  // 全局函数类外实现
  // friend void printPerson1(Person<NameType, AgeType> p);
  // 普通函数和函数模板不同 需加入空模板参数列表 和前向声明
  // 或者
  // template <class NameType, class AgeType>
  // friend void printPerson(Person<NameType, AgeType> p);
  friend void printPerson1<>(Person<NameType, AgeType> p);

  public:
    Person(NameType name, AgeType age){
      this->m_name = name;
      this->m_age =age;
    }
  
  private:
      NameType m_name;
      AgeType m_age;
};

void test1() {
  Person<string, int> p("33", 4);
  printPerson(p);
}

int main() {
  test1();
}
