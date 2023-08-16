#include <iostream>
using namespace std;

int main() {
    string str = "D:\test.cpp";
    cout << str << endl;
    string str1 = "D:\\test.cpp";
    cout << str1 << endl;
    string str2 = R"(D:\test.cpp)";
    cout << str2 << endl;
}