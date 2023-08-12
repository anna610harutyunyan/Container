#include "Vector.h"
#include <iostream>
namespace MyVector {
    template class Vector<int>;
    template class Vector<char>;
    template class Vector<double>;

    template <typename T>
    Vector<T>::Vector(int capacity) : capacity(capacity) {
        ptr = new T[capacity];
       // std::cout << "Call parametrized constructor" << std::endl;
    }

    template <typename T>
    Vector<T>::Vector(const Vector& obj) {
        this->capacity = obj.capacity;
        this->m_size = obj.m_size;
        this->ptr = new T[capacity];
        for (int i = 0; i < m_size; ++i) {
            ptr[i] = obj.ptr[i];
        }
       // std::cout << "Call Copy" << std::endl;
    }

    template <typename T>
    Vector<T>& Vector<T>::operator=(const Vector& other) {
        if (this == &other) {
            return *this;
        }
        this->capacity = other.capacity;
        this->m_size = other.m_size;
        delete[] this->ptr;
        this->ptr = new T[capacity];
        for (int i = 0; i < m_size; ++i) {
            ptr[i] = other.ptr[i];
        }
        //std::cout << "Call operator=" << std::endl;

        return *this;
    }

    template <typename T>
    Vector<T>::Vector(Vector&& obj) {
        this->m_size = obj.m_size;
        this->capacity = obj.capacity;
        this->ptr = obj.ptr;
        obj.m_size = 0;
        obj.ptr = nullptr;
       // std::cout << "Call move constructor" << std::endl;
    }

    template <typename T>
    Vector<T>& Vector<T>::operator=(Vector&& obj) {
        if (this != &obj) {
            delete[] this->ptr;
            this->capacity = obj.capacity;
            this->m_size = obj.m_size;
            this->ptr = obj.ptr;
            obj.m_size = 0;
            obj.capacity = 0;
            obj.ptr = nullptr;
        }
        //std::cout << "Call move operator assignment" << std::endl;
        return *this;
    }

    template <typename T>
    T& Vector<T>::operator[](int index) {
        if (index < 0 || index >= m_size) {
            throw std::out_of_range("Check the index");
        }
        return ptr[index];
    }

    template <typename T>
    Vector<T>::~Vector() {
       // std::cout << "Call destructor" << std::endl;
        delete[] ptr;
        ptr = nullptr;
    }

    template <typename T>
    void Vector<T>::Push_back(T newValue) {
        if (m_size >= capacity) {
            capacity *= 2;
            T* newPtr = new T[capacity];

            for (int i = 0; i < m_size; ++i) {
                newPtr[i] = ptr[i];
            }
            newPtr[m_size] = newValue;
            delete[] ptr;
            ptr = newPtr;
        }
        else {
            ptr[m_size] = newValue;
            m_size++;
        }

      //  std::cout << "Push_back" << std::endl;
    }

    template <typename T>
    void Vector<T>::Pop_back() {
        if (m_size > 0) {
            m_size--;
           // std::cout << "Pop_back" << std::endl;
        }
    }

    template <typename T>
    void Vector<T>::Clean() {
        for (int i = (m_size - 1); i >= 0; i--) {
            Pop_back();
        }
       // std::cout << "Vector is empty" << std::endl;
    }

    template <typename T>
    void Vector<T>::Print() const {
        for (int i = 0; i < m_size; ++i) {
            std::cout << ptr[i] << ' ';
        }
        std::cout << std::endl;
    }

    template <typename T>
    void Vector<T>::Erase(int index) {
        if (index < 0 || index >= m_size) {
            return;
        }
        for (int i = index; i < (m_size - 1); ++i) {
            ptr[i] = ptr[i + 1];
        }
        m_size--;
    }
}