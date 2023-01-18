#include <iostream>
#include <string>
using namespace std;
// 建立一个通用的类，类中的成员 数据类型可以不具体指定，用一个虚拟的类型来代表
template<class NameType, class AgeType>
class Person {
  public:
    // Person<class NameType, class AgeType>
    Person(NameType name, AgeType age){
      this->m_name = name;
      this->m_age =age;
    }
    NameType m_name;
    AgeType m_age;
};
int main() {
  Person<string, int> p1("aa", 12);

}
