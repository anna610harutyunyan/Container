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
	void merge(int left, int mid, int right)
	{
		int s1 = mid - left + 1;
		int s2 = right - mid;

		T* V1 = new T[s1];
		T* V2 = new T[s2];

		for (int i = 0; i < s1; ++i)
		{
			V1[i] =this-> ptr[left+i];
		}
		for (int j = 0; j < s2; ++j)
		{
			V2[j] = this->ptr[mid + 1 + j];
		}
		int i = 0; //index of 1st vec
		int j = 0;//index of 2nd vec
		int k = left;//index of merged vec

		while (i < s1 && j < s2)
		{
			if (V1[i] < V2[j])
			{
				ptr[k] = V1[i];
				i++;
			}
			else
			{
				ptr[k] = V2[j];
				j++;
			}
			k++;
		}

		while (i < s1)
		{
			ptr[k] = V1[i];
			i++;
			k++;
		}
		while (j < s2)
		{
			ptr[k] = V2[j];
			j++;
			k++;

		}
	}
	void mergeSort( int begin, int end)
	{
		if(begin<end)
		{
			int mid = begin + (end - begin) / 2;
			mergeSort( begin, mid);
			mergeSort(mid + 1, end);
			merge(begin, mid, end);
		}
	}
	void mergeSort()
	{
		mergeSort( 0, m_size - 1);
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
	obj.Push_back(100);
	obj.Push_back(1);
	obj.Push_back(-9);
	std::cout << "Original vector:: ";
	obj.Print();
	obj.mergeSort();
	std::cout << "Vector after Merge sort:: ";
	obj.Print();
	

	return 0;
}