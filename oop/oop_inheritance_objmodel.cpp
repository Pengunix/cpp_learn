#include <iostream>
using std::cout;
using std::endl;

// 继承中的对象模型
class Base {
    public:
        int m_A;
    protected:
        int m_B;
    private:
        int m_C;
};

class Son :public Base {
    public:
        int m_D;
};
// 使用 gcc -fdump-lang-class 查看类对象模型
int main() {
    // 16
    cout << "size of Son : " << sizeof(Son) << endl;
    return 0;
}