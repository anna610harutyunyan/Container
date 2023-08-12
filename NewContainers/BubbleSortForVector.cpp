#include <iostream>
template <typename T>

class Vector
{
	int m_size;
	int capacity;
	T* ptr = nullptr;
public:
	Vector<T>(int capacity) : capacity(capacity)
	{
		ptr = new T[capacity];
		//std::cout << "Call parametrized constructor " << std::endl;
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
		//std::cout << " Call Copy" << __func__ << std::endl;
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
		//std::cout << "Call " << __func__ << std::endl;

		return *this;

	}
	Vector(Vector&& obj)
	{
		this->m_size = obj.m_size;
		this->capacity = obj.capacity;
		this->ptr = obj.ptr;
		obj.m_size = 0;
		obj.ptr = nullptr;
		//std::cout << "Call move constructor " << std::endl;

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
		//std::cout << "Call move operator assignment " << std::endl;
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
		//std::cout << "Call destructor " << std::endl;
		delete[] ptr;
		ptr = nullptr;
	}
public:
	void Push_back(T newValue)
	{
		if (m_size >= capacity)
		{
			capacity *= 2;
			T* newPtr = new T[capacity];

			for (int i = 0; i < m_size; ++i)
			{
				newPtr[i] = ptr[i];
			}
			newPtr[m_size] = newValue;
			delete[] ptr;
			ptr = newPtr;

		}
		else
		{
			ptr[m_size] = newValue;
			m_size++;

		}
		
		//std::cout << __func__ << std::endl;
	}

	void Pop_back()
	{
		if (m_size > 0)
		{
			m_size--;
			//std::cout << __func__ << std::endl;
		}
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
	void bubbleSort()
	{
		if (m_size == 0 || m_size == 1)
		{
			std::cout << "No need to use sorting \n";
			return;
		}
		bool swapped;
		int i = 0;
		do
		{

			swapped = false;
			for (int j = 0; j < m_size - i; ++j)
			{
				if (ptr[j] > ptr[j + 1])
				{
					T temp = ptr[j];
					ptr[j] = ptr[j + 1];
					ptr[j + 1] = temp;
					swapped = true;
				}

			}
			i++;
		} while (swapped);
	}
};


int main(int argc, char** argv)
{
	Vector <int> obj(5);
	obj.Push_back(5);
	obj.Push_back(3);
	obj.Push_back(15);
	obj.Push_back(35);
	obj.Push_back(20);
	obj.Push_back(60);
	std::cout << "Original vector:: ";
	obj.Print();
	obj.bubbleSort();
	std::cout << "Vector after bubble sort:: ";
	obj.Print();
	obj.Clean();
	std::cout << "Vector after clean :: ";
	obj.Print();

	return 0;
}