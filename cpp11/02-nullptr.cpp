#include <iostream>
using namespace std;

void func(int a) {
    cout << "int" << endl;
}
void func(char *p) {
    cout << "char*" << endl;
}

int main() {
    func(10);
    func(nullptr);
}