#include <iostream>
using namespace std;

template<class T>
class IntSLLNode {
  public:
    IntSLLNode() { next = 0; }
    IntSLLNode(T i, IntSLLNode *in = 0) {
        info = i;
        next = in;
    }
    T info;         // 储存信息
    IntSLLNode *next; // 下一个节点
};

int main() {
  IntSLLNode<int> * p = new IntSLLNode<int>(10);
  p->next = new IntSLLNode<int>(8);
  p->next->next = new IntSLLNode<int>(666); // 符号非常繁琐，需要改进
}
