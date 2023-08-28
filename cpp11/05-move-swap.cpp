#include <iostream>
using namespace std;

template<typename T>
class unique_ptr
{
    T* ptr;

public:

    
    explicit unique_ptr(T* p = nullptr)
    {
        ptr = p;
    }

    ~unique_ptr()
    {
        delete ptr;
    }
    
    // move constructor
    unique_ptr(unique_ptr&& source)   // note the rvalue reference
    {
        ptr = source.ptr;
        source.ptr = nullptr;
    }
    
 /*    unique_ptr& operator=(unique_ptr&& source)   // 这里使用右值引用
    {
        if (this != &source)    // beware of self-assignment
        {
            delete ptr;         // release the old resource

            ptr = source.ptr;   // acquire the new resource
            source.ptr = nullptr;
        }
        return *this;
    } */
    
    // move and swap  idiom replace the move assignment operator
    unique_ptr& operator=(unique_ptr rhs)   // 这里不用引用，会调用移动构造函数
    {
        std::swap(ptr, rhs.ptr);
        // std::swap(*this,rhs)  // is also ok
        return *this;
    }
    
    
    
    T* operator->() const
    {
        return ptr;
    }

    T& operator*() const
    {
        return *ptr;
    }
};