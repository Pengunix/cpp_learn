#include <iostream>
using namespace std;

// 继承中 构造和析构顺序
// 先调用父类构造再子类构造 先子类析构再父类析构
class Base {
    public:
        Base() {
            cout << "Base construct" << endl;
        }
        ~Base() {
            cout << "Base destruct" << endl;
        }
};

class Son :public Base {
    public:
        Son() {
            cout << "Son construct" << endl;
        }
        ~Son() {
            cout << "Son destruct" << endl;
        }
};
int main() {
    Son a;
}