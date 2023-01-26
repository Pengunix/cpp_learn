#include <iostream>
using namespace std;


class Person
{
public:
  Person() = default;
  Person(Person &&) = default;
  Person(const Person &) = default;
  Person &operator=(Person &&) = default;
  Person &operator=(const Person &) = default;
  ~Person() = default;

private:
  
};
struct A
{
  int a; 
};

int main() {
  cout << "好" << '\n';

}
