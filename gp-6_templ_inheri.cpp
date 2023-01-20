#include <iostream>
using namespace std;
// 类模板与继承
// 当子类继承的模板是一个类模板时，子类在声明继承时，要指定父类T类型
// 如果不指定，编译器无法给子类分配内存
// 如果想要灵活指定父类T的类型，子类也需变为模板

template<class T>
class Base {
  T m;
};

// 当子类继承的模板是一个类模板时，子类在声明继承时，要指定父类T类型
class Derived:public Base<int> {
  
};

void test1() {
  Derived d;
}

// 如果想要灵活指定父类T的类型，子类也需变为模板
template<class T1, class T2>
class Derived1:public Base<T2> {
public:
  Derived1() {
    cout << "T1: " << typeid(T1).name() << endl;
    cout << "T2: " << typeid(T2).name() << endl;
  }
  T1 c;
};

void test2() {
  Derived1<int, char> d2;
}

int main() {
  // test1();
  test2();
  return 0;
}
