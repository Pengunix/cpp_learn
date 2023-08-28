#include <iostream>
using namespace std;

class IntSLLNode {
public:
  IntSLLNode() { next = 0; }

  IntSLLNode(int el, IntSLLNode *ptr = 0) {
    info = el;
    next = ptr;
  }
  int info;
  IntSLLNode *next;
};

class IntSLList {
public:
  IntSLList() { head = tail = 0; }
  ~IntSLList(){
    for (IntSLLNode *p;!isEmpty();) {
      p = head->next;
      delete head;
      head = p;
    }
  }
  bool isEmpty() { return head == 0; }
  void addToHead(int el) {
    head = new IntSLLNode(el, head);
    if (tail == 0) {
      tail = head;
    }
  }
  void addToTail(int el) {
    if (tail != 0) {
      tail->next = new IntSLLNode(el);
      tail = tail->next;
    } else {
      head = tail = new IntSLLNode(el);
    }
  }
  int deleteFromHead() {
    int el = head->info;
    IntSLLNode *tmp = head;
    if (head == tail) {
      head = tail = 0;
    } else {
      head = head->next;
    }
    delete tmp;
    return el;
  }
  int deleteFromtail() {
    int el = tail->info;
    if (head == tail) {
      delete head;
      head = tail = 0;
    } else {
      IntSLLNode *tmp;
      for (tmp = head; tmp->next != tail; tmp = tmp->next);
      delete tail;
      tail = tmp;
      tail->next = 0;
    }
    return el;
  }
  void deleteNode(int el) {
    if (head != 0) {
      if (head == tail && el == head->info) {
        delete head;
        head = tail = 0;
      } else if (el == head->info) {
        IntSLLNode *tmp = head;
        head = head->next;
        delete tmp;
      } else {
        IntSLLNode *pred, *tmp;
        for (pred = head, tmp = head->next; tmp != 0 && !(tmp->info == el);
             pred = pred->next, tmp = tmp->next)
          ;
        if (tmp != 0) {
          pred->next = tmp->next;
          if (tmp == tail) {
            tail = pred;
          }
          delete tmp;
        }
      }
    }
  }
  void reverse() {
    IntSLLNode * tmp,*pred=head,*cur=head->next;
    head->next = 0;

    while (cur!=0) {
      tmp = cur;
      cur->next = pred; 
      cur = tmp->next;
      pred = tmp;
    }
  }

  bool isInList(int el) const {
    IntSLLNode *tmp;
    for (tmp = head; tmp != 0 && !(tmp->info == el); tmp = tmp->next)
      ;
    return tmp != 0;
  }
  void printList() {
    IntSLLNode *tmp = head;
    while (tmp != 0) {
      cout << tmp->info << " ";
      tmp = tmp -> next;
    }
    cout << endl;
  }
  void printpointer() {
    cout << head << endl;
    cout << tail << endl;
  }

private:
  IntSLLNode *head, *tail;
};

int main() {
  IntSLList a;
  a.addToHead(11);
  a.addToHead(3);
  a.addToTail(12);
  a.addToTail(6);
  a.addToTail(8);
  a.addToTail(99);
  a.addToTail(56);

  a.printList();
  a.reverse();
  a.printList();
}