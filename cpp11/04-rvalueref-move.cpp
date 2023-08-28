/*
左值：可以取地址并且有名字的东西就是左值。
右值：不能取地址的没有名字的东西就是右值。
纯右值：运算表达式产生的临时变量、不和对象关联的原始字面量、非引用返回的临时变量、lambda表达式等都是纯右值。
将亡值：可以理解为即将要销毁的值。
左值引用：对左值进行引用的类型。
右值引用：对右值进行引用的类型。
移动语义：转移资源所有权，类似于转让或者资源窃取的意思，对于那块资源，转为自己所拥有，别人不再拥有也不会再使用。
完美转发：可以写一个接受任意实参的函数模板，并转发到其它函数，目标函数会收到与转发函数完全相同的实参。
返回值优化：当函数需要返回一个对象实例时候，就会创建一个临时对象并通过复制构造函数将目标对象复制到临时对象，
这里有复制构造函数和析构函数会被多余的调用到，有代价，而通过返回值优化，C++标准允许省略调用这些复制构造函数。
*/
#include <cstring>
#include <iostream>

using namespace std;

class A {
public:
  A() : i(new int[500]) { cout << "class A construct!" << endl; }
  A(const A &a) : i(new int[500]) {
    memcpy(i, a.i, 500 * sizeof(int));
    cout << "class A copy!" << endl;
  }
  A(A &&a) noexcept : i(a.i) {
    a.i = nullptr;
    cout << "class A move" << endl;
  }
  A &operator=(A &&rhs) noexcept {
    // check self assignment
    if (this != &rhs) {
      delete[] i;
      i = rhs.i;
      rhs.i = nullptr;
    }
    cout << "class A move and assignment" << std::endl;
    return *this;
  }
  ~A() {
    delete[] i;
    cout << "class A destruct!" << endl;
  }

private:
  int *i;
};

A get_A_value() { return A(); }
void pass_A_by_value(A a) {}

void swapa(A &a1, A &a2) {
  A tmp(std::move(a1));
  a1 = std::move(a2);
  a2 = std::move(tmp);
}

int main() {
  A a = get_A_value();
  A b;
  swap(a, b);
  return 0;
}