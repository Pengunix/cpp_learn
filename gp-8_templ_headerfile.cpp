#include <iostream>
using namespace std;
// 模板的分文件编写
// 1. person.h person.cpp 分开写 main.cpp include person.cpp
// 2. .h .cpp写在一个.hpp中 main.cpp include person.hpp
template<class T1, class T2>
class Person {
  public:
    Person(T1 name, T2 age);
    void showPerson();
    
    T1 m_name;
    T2 m_age;
};

