#include <iostream>
using namespace std;

template<class T>
class SLLNode {
public:
  SLLNode(T &el, SLLNode<T> *n = nullptr) {
    info = el;
    next = n;
  }
  T info;
  SLLNode<T> *next;
};

template<class T>
class SLLoop {
  public:
    SLLoop(T el) {
      tail = new SLLNode<T>(el);
      tail->next = tail;
    }
    ~SLLoop() {
      SLLNode<T> *tmp = tail;
      if (tail == tail->next) {
        delete tail;
        return;
      }
      while(tail->next != tmp) {
        delete tail;
        tail = tail->next;
      }
    }
    void addBehTail(T el) {
      tail->next = new SLLNode<T>(el, tail->next);
      tail = tail->next;
    }
    void printlist() {
      SLLNode<T> *tmp = tail;
      do {
        cout << tmp->info << " ";
        tmp = tmp->next;
      } while(tmp!=tail);
      cout << endl;
    }
  protected:
    SLLNode<T> *tail;
};

int main() {
  SLLoop<int> a(1);
  // a.printlist();
  a.addBehTail(2);
  a.addBehTail(3);
  a.addBehTail(4);

  a.printlist();
}