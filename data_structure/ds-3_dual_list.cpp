#include <iostream>
using namespace std;

template<class T>
class DLLNode {
  public:
    DLLNode() {
      next = prev = nullptr;
    }
    DLLNode(const T& el, DLLNode *n = nullptr, DLLNode *p = nullptr) {
      info = el;
      next = n;
      prev = p;
    }
    T info;
    DLLNode *next, *prev;
};

template<class T>
class DLL {
  public:
    DLL() {
      head = tail = nullptr;
    }
    void addToTail(const T& el) {
      if (tail != nullptr) {
        tail = new DLLNode<T>(el, nullptr, tail);
        tail->prev->next = tail;
      } else {
        head = tail = new DLLNode<T>(el);
      }
    }
    ~DLL() {
      while(head!=nullptr) {
        delete head;
        if (head->next != nullptr) head = head->next;
      }
    }
    T deleteFromTail() {
      T el = tail->info;
      if (head == tail) {
        delete head;
        head = tail = nullptr;
      } else {
        tail = tail->prev;
        delete tail->next;
        tail->next = nullptr;
      }
      return el;
    }
    void printList() {
      for (DLLNode<T> *tmp=head;tmp != nullptr;tmp = tmp->next) {
        cout << tmp->info << " ";
      }
      cout << endl;
    }
    void printBack() {
      for (DLLNode<T> *tmp=tail;tmp!=nullptr;tmp=tmp->prev) {
        cout << tmp->info << " ";
      }
      cout << endl;
    }
  protected:
    DLLNode<T> *head, *tail;
};


int main() {
  DLL<int> a;
  a.addToTail(11);
  a.addToTail(12);
  a.addToTail(13);
  a.printList();
  a.printBack();
  return 0;
}