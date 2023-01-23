#include <iostream>
#include <string>
using namespace std;

void test() {
  string s1;
  const char * str = "hello world";
  string s2(str);
  // cout << s2 << endl;

  string s3(s2);
  // cout << s3 << endl;

  string s4(10, 'a');
  // cout << s4 << endl;

  string s5 = "aaa";

  string s6 = s5;

  s1.assign("aaa");

  s5 += s2;

  s5.append(s2);

  // find 是从左往右查找
  cout << (int)s2.find("bl") << endl;
  // rfind 是从右往左查找
  cout << (int)s2.rfind("bl") << endl;

  s2.replace(1, 3, "hhhhh");
  cout << s2 << endl;

  // ascii 码比较 三种结果 -1 0 1
  cout << (int)s2.compare(s1) << endl;

  cout << s2[1] << endl;
  s2[1] = 'b';
  cout << s2.at(1) << endl;

  string sss = "abcdefg";
  sss.insert(1, "111");
  cout << sss << endl;
  sss.erase(1, 3);
  cout << sss << endl;

  cout << sss.substr(1, 3) << endl;

}

int main() {
  test();
  return 0;
}
