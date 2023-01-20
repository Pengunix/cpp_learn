#include <iostream>
using namespace std;

// 案例：实现一个通用的数组类
//  可以对内置的数据类型以及自定义数据类型进行存储
//  将数组数据存到堆区
//  构造函数中可传入数组的容量
//  提供对应的拷贝构造函数以及重载赋值运算符 解决浅拷贝
//  提供尾部插入和尾部删除方法
//  可通过下标访问数组
//  可获取数组中元素个数和数组大小

template<class T>
class MyArray {
  public:
    MyArray(int capacity) {
      // cout << "arg constructor" << endl;
      this->m_Capacity = capacity;
      this->m_Size = 0;
      this->pAddress = new T[this->m_Capacity];
    }

    MyArray(const MyArray &arr) {
      // cout << "Copy constructor" << endl;
      this->m_Capacity = arr.m_Capacity;
      this->m_Size = arr.m_Size;
      // 浅拷贝
      // this->pAddress = arr.m_Size;
      // 深拷贝
      this->pAddress = new T[arr.m_Capacity];
      // 拷贝数据
      for (int i=0;i<this->m_Size;i++) {
        this->pAddress[i] = arr.pAddress[i];
      }
    }

    MyArray& operator=(const MyArray &arr) {
      // 先判断原来堆区是否有数据，如果有 先释放
      // cout << "operator=" << endl;
      if (this->pAddress != NULL) {
        delete [] this->pAddress;
        this->pAddress = NULL;
        this->m_Capacity = 0;
        this->m_Size = 0;
      }

      
      this->m_Capacity = arr.m_Capacity;
      this->m_Size = arr.m_Size;
      this->pAddress = new T[arr.m_Capacity];
      for (int i=0;i<this->m_Size;i++) {
        this->pAddress[i] = arr.pAddress[i];
      }
      return *this;
    }
    
    void insert(const T & value) {
      if (this->m_Capacity == this->m_Size)  {
        return;
      }
      this->pAddress[this->m_Size] = value;
      this->m_Size++;
    }

    void pop() {
      if(this->m_Size == 0) {
        return;
      }
      this->m_Size--;
    }

    T& operator[] (int index) {
      return this->pAddress[index];
    }

    int getCapcity() {
      return this->m_Capacity;
    }

    int getSize() {
      return this->m_Size;
    }
    
    ~MyArray() {
      // cout << "Destructor" << endl;
      if (this->pAddress != NULL) {
        delete [] this->pAddress;
        this->pAddress = NULL;
      }
    }
  private:
    T * pAddress; // 指向堆区的数组
    int m_Capacity;
    int m_Size;
};

void print(MyArray<int> &arr) {
  for (int i=0;i<arr.getSize();i++) {
    cout << arr[i] << endl;
  }
}

void test1() {
  MyArray<int> arr(10);
  //MyArray<int> arr1(arr);
  //MyArray<int> arr2(100);
  //arr2 = arr1;
  for (int i=0;i<10;i++) {
    arr.insert(i);
  }
  // arr.pop();
  print(arr);
}

int main() {
  test1();
  return 0;
}
