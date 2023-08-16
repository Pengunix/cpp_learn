#include <iostream>
using namespace std;
class IntSLLNode {
  public:
    IntSLLNode() { next = 0; }
    IntSLLNode(int i, IntSLLNode *in = 0) {
        info = i;
        next = in;
    }
    int info;         // 储存信息
    IntSLLNode *next; // 下一个节点
};

int main() {
  IntSLLNode * p = new IntSLLNode(10);
  p->next = new IntSLLNode(8);
  p->next->next = new IntSLLNode(666); // 符号非常繁琐，需要改进
}
