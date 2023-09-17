#include <algorithm>
#include <iostream>
#include <vector>

// 谓词：返回bool的仿函数
// 如果operator() 接收一个参数则为一元谓词 两个参数为二元谓词
class GreaterFive {
public:
  bool operator()(int val) { return val > 5; }
};

class Compare {
public:
  bool operator()(int val1, int val2) { return val1 > val2; }
};

void print(const std::vector<int> &v) {
  for (const int &i : v) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}

void test() {
  std::vector<int> v;
  for (int i = 0; i < 10; i++) {
    v.push_back(i);
  }
  // 查找有没有大于5的数字
  std::vector<int>::iterator it =
      std::find_if(v.begin(), v.end(), GreaterFive());
  if (it == v.end()) {
    std::cout << "Not found" << std::endl;
  } else {
    std::cout << "Found: " << *it << std::endl;
  }
}

void test1() {
  std::vector<int> v;
  v.push_back(23);
  v.push_back(45);
  v.push_back(73);
  v.push_back(12);
  v.push_back(9);

  std::sort(v.begin(), v.end());
  print(v);

  std::sort(v.begin(), v.end(), Compare());
  print(v);
}

int main() {
  // test();
  test1();
}
