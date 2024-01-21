#include <cassert>
#include <iostream>
#include <regex>
using namespace std;

int main() {
  // 正则匹配
  std::regex reg("<.*>.*</.*>");
  bool ret = std::regex_match("<html>value</html>", reg);
  assert(ret);

  ret = std::regex_match("<xml>value<xml>", reg);
  assert(!ret);

  std::regex reg1("<(.*)>.*</\\1>");
  ret = std::regex_match("<xml>value</xml>", reg1);
  assert(ret);

  ret = std::regex_match("<header>value</header>",
                         std::regex("<(.*)>value</\\1>"));
  assert(ret);

  // 使用basic文法
  std::regex reg2("<\\(.*\\)>.*</\\1>", std::regex_constants::basic);
  ret = std::regex_match("<title>value</title>", reg2);
  assert(ret);
  std::regex reg3("<.*>.*</.*>");
  ret = std::regex_match("<html>value</html>", reg3);

  // 正则匹配结果
  std::cmatch m;
  ret =
      std::regex_match("<xml>value</xml>", m, std::regex("<(.*)>(.*)</(\\1)>"));
  if (ret) {
    std::cout << m.str() << std::endl;
    std::cout << m.length() << std::endl;
    std::cout << m.position() << std::endl;
  }

  std::cout << "----------------" << std::endl;

  // 遍历匹配内容
  for (auto i = 0; i < m.size(); ++i) {
    // 两种方式都可以
    std::cout << m[i].str() << " " << m.str(i) << std::endl;
  }

  std::cout << "----------------" << std::endl;

  // 使用迭代器遍历
  for (auto pos = m.begin(); pos != m.end(); ++pos) {
    std::cout << *pos << std::endl;
  }

  // 正则搜索 只要字符串中有目标出现就会返回，而非完全「匹配」
  std::regex reg7("<(.*)>(.*)</(\\1)>");
  std::cmatch m1;
  ret = std::regex_search("123<xml>value</xml>456", m1, reg7);
  if (ret) {
    for (auto &elem : m1)
      std::cout << elem << std::endl;
  }

  std::cout << "prefix:" << m1.prefix() << std::endl;
  std::cout << "suffix:" << m1.suffix() << std::endl;

  std::regex reg8("<(.*)>(.*)</(\\1)>");
  std::string content("123<xml>value</xml>456<widget>center</"
                      "widget>hahaha<vertical>window</vertical>the end");
  std::smatch m2;
  auto pos = content.cbegin();
  auto end = content.cend();
  for (; std::regex_search(pos, end, m2, reg8); pos = m2.suffix().first) {
    std::cout << "----------------" << std::endl;
    std::cout << m2.str() << std::endl;
    std::cout << m2.str(1) << std::endl;
    std::cout << m2.str(2) << std::endl;
    std::cout << m2.str(3) << std::endl;
  }
  // 分词 Tokenize 分割
  std::string mail("123@qq.vip.com,456@gmail.com,789@163.com,abcd@my.com");
  std::regex reg9(",");
  std::sregex_token_iterator pos1(mail.begin(), mail.end(), reg9, -1);
  decltype(pos1) end1;
  for (; pos1 != end1; ++pos1) {
    std::cout << pos1->str() << std::endl;
  }

  char data[] = "he...ll..o, worl..d!";
  std::regex reg10("\\.");
  // output: hello, world!
  std::cout << std::regex_replace(data, reg10, "");

  char data2[] = "001-Neo,002-Lucia";
  std::regex reg11("(\\d+)-(\\w+)");
  // output: 001 name=Neo,002 name=Lucia
  std::cout << std::regex_replace(data2, reg11, "$1 name=$2");
}

/*
正则文法
^	匹配行的开头
$	匹配行的结尾
.	匹配任意单个字符
[…]	匹配[]中的任意一个字符
(…)	设定分组
\	转义字符
\d	匹配数字[0-9]
\D	\d 取反
\w	匹配字母[a-z]，数字，下划线
\W	\w 取反
\s	匹配空格
\S	\s 取反
+	前面的元素重复1次或多次
*	前面的元素重复任意次
?	前面的元素重复0次或1次
前面的元素重复n次
前面的元素重复至少n次
前面的元素重复至少n次，至多m次
|	逻辑或
回溯和断言待补充
https://blog.pengunix.club/1674356899.html
*/