#ifndef VECTOR_H
#define VECTOR_H

namespace MyVector {
    template <typename T>
    class Vector {
    private:
        int m_size;
        int capacity;
        T* ptr = nullptr;

    public:
        Vector(int capacity);
        Vector(const Vector& obj);
        Vector& operator=(const Vector& other);
        Vector(Vector&& obj);
        Vector& operator=(Vector&& obj);
        T& operator[](int index);
        ~Vector();

        void Push_back(T newValue);
        void Pop_back();
        void Clean();
        void Print() const;
        void Erase(int index);
    };
}


#endif // VECTOR_H

