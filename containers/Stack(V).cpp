#include <iostream>
template <typename T>

class Vector
{
	int m_size;
	int capacity;
	T* ptr = nullptr;
	T* topElement = nullptr;
public:
	Vector()
	{
		std::cout << "Call constructor for Vector " << std::endl;
	}
	Vector<T>(int capacity) : capacity(capacity)
	{
		ptr = new T[capacity];
		std::cout << "Call parametrized constructor " << std::endl;
	}
	Vector(const Vector& obj)
	{
		this->capacity = obj.capacity;
		this->m_size = obj.m_size;
		this->ptr = new T[capacity];
		for (int i = 0; i < m_size; ++i)
		{
			ptr[i] = obj.ptr[i];
		}
		std::cout << " Call Copy" << __func__ << std::endl;
	}
	Vector& operator=(const Vector& other)
	{
		if (this == &other)
		{
			return *this;
		}
		this->capacity = other.capacity;
		this->m_size = other.m_size;
		delete[] this->ptr;
		this->ptr = new T[capacity];
		for (int i = 0; i < m_size; ++i)
		{
			ptr[i] = other.ptr[i];
		}
		std::cout << "Call " << __func__ << std::endl;

		return *this;

	}
	Vector(Vector&& obj)
	{
		this->m_size = obj.m_size;
		this->capacity = obj.capacity;
		this->ptr = obj.ptr;
		obj.m_size = 0;
		obj.ptr = nullptr;
		std::cout << "Call move constructor " << std::endl;

	}
	Vector& operator =(Vector&& obj)
	{
		if (this != &obj)
		{
			delete[] this->ptr;
			this->capacity = obj.capacity;
			this->m_size = obj.m_size;
			this->ptr = obj.ptr;
			obj.m_size = 0;
			obj.capacity = 0;
			obj.ptr = nullptr;
		}
		std::cout << "Call move operator assignment " << std::endl;
		return *this;

	}
	T& operator [](int index)
	{
		if (index < 0 || index >= m_size)
		{
			throw std::out_of_range("Check the index ");
		}
		return ptr[index];
	}
	~Vector()
	{
		std::cout << "Call destructor for Vector " << std::endl;
		delete[] ptr;
		ptr = nullptr;
	}
public:
	void Push_back(T newValue)
	{
		if (m_size == capacity)
		{
			capacity *= 2;
			T* newPtr = new T[capacity];

			for (int i = 0; i < m_size; ++i)
			{
				newPtr[i] = ptr[i];
			}

			delete[] ptr;
			ptr = newPtr;
		}

		ptr[m_size] = newValue;
		topElement = &ptr[m_size];
		m_size++;
		std::cout << __func__ << std::endl;
	}

	void Pop_back()
	{
		if (m_size > 0)
		{
			m_size--;
			topElement = &ptr[m_size - 1];
			std::cout << __func__ << std::endl;
		}
	}
	const T& Top()const
	{
		return *topElement;
	}
	void Clean()
	{
		for (int i = (m_size - 1); i >= 0; i--)
		{
			Pop_back();
		}
		std::cout << "Vector is empty " << std::endl;
	}


	void Print()const
	{
		for (int i = 0; i < m_size; ++i)
		{
			std::cout << ptr[i] << ' ';
		}
		std::cout << std::endl;
	}
	void Erase(int  index)
	{
		if (index < 0 || index >= m_size)
		{
			return;
		}
		for (int i = index; i < (m_size - 1); ++i)
		{
			ptr[i] = ptr[i + 1];
		}
		m_size--;
	}

};
template <typename T>
class Stack :private Vector<T>
{

public:
	using Vector<T>::Vector;
    Stack() :Vector<T>()
    {
	   std::cout << "Call constructor for Stack " << std::endl;
     }
	~Stack()
	{ 
		std::cout << "Call destructor for Stack " << std::endl;
	}
public:

	void Push(T value)
	{
		Vector<T>::Push_back(value);
	}
	void Pop()
	{
		Vector<T>::Pop_back();

	}
	const T& Top()const
	{
		return Vector<T>::Top();
	}

	void PrintStack()
	{
		Vector<T>::Print();
	}
};

int main(int argc, char** argv)
{
	Stack<int> stack;
	stack.Push(5);
	stack.Push(7);
	stack.Push(6);
	stack.Push(3);
	stack.Push(11);
	stack.PrintStack();
	std::cout <<"Top member of the stck is " <<stack.Top() <<std::endl;
	stack.Pop();
	stack.Pop();
	stack.PrintStack();
	std::cout << "Top member of the updated stck is " << stack.Top() << std::endl;

	return 0;

}