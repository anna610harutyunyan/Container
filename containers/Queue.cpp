#include <iostream>

template <typename T>

struct Node
{
	T data;
	Node* next;
	Node* previous;
	Node()
	{
		data = 0;
		next = nullptr;
		previous = nullptr;
	}
	Node(T value) :data(value), next(nullptr), previous(nullptr) {};
	~Node() {}


};

template <typename T>
class List :public Node<T>
{
	Node<T>* head;
	Node<T>* tail;
	Node<T>* firstElement;
	Node<T>* lastElement;

public:
	List()
	{
		head = nullptr;
		tail = nullptr;
		std::cout << "Call List constructor" << std::endl;
	}
	~List()
	{
		std::cout << "Call List destructor" << std::endl;
	}

public:
	void InsertElement(const T& data)
	{
		Node<T>* newNode = new Node<T>(data);
		if (head == nullptr)
		{
			head = tail = newNode;
		}
		else
		{
			tail->next = newNode;
			newNode->previous = tail;
			tail = newNode;
			lastElement = newNode;
			firstElement = head;
		}
	}
	void removeElement()
	{
		if (head == nullptr && tail == nullptr)
		{
			std::cout << "List is empty" << std::endl;
		}
		else
		{
			Node<T>* temp = head;
			head = head->next;
			if (head)
			{
				head->previous = nullptr;
			}
			
			delete temp;
			firstElement = head;
		}
	}
	void PrintForward()
	{
		Node<T>* traverser = head;
		while (traverser != nullptr)
		{
			std::cout << traverser->data << ' ';
			traverser = traverser->next;
		}
	}
	void PrintBackward()
	{
		Node<T>* traverser = tail;
		while (traverser != nullptr)
		{
			std::cout << traverser->data << ' ';
			traverser = traverser->previous;
		}
	}
	const T& Front()
	{
		return firstElement->data;
	}
	const T& Back()
	{
		return lastElement->data;
	}
};
 template <typename T>
class Queue :private List<T>
{

	int size;
public:
	using List<T>::List;
	Queue() :List<T>()
	{
		std::cout << "Call Queu constructor" << std::endl;
	}
	~Queue()  
	{
		std::cout << "Call Queue destructor" << std::endl;

	}

public:
	void Push(T value)
	{
		List<T>::InsertElement(value);
		size++;
	}

	void Pop()
	{
		if (size == 0)
		{
			std::cout << "Queue is empty" << std::endl;
		}
		else
		{
			List<T>::removeElement(); 
			size--;
		}
	}
	void printQue()
	{
		List<T>::PrintForward();
	}
	const T& Front()
	{
		return 	List<T>::Front();

	}
	const T& Back()
	{
		return	List<T>::Back();

	}
int get_size()const

	{
		return size;
	}
	
};


int main(int argc, char** argv)
{
	Queue<int> queue;
	queue.Push(5);
	queue.Push(6);
	queue.Push(78);
	queue.Push(9);
	queue.Push(15);
	queue.printQue();
	std::cout << std::endl;
	std::cout << "First element is " << queue.Front() << std::endl;
	std::cout << "Last element is " << queue.Back() << std::endl;
	std::cout << "The size of the que is " << queue.get_size() << std::endl;
	queue.Pop();
	queue.Pop();
	queue.printQue();
	std::cout << std::endl;
	std::cout<<"The first element of updated queue is " << queue.Front() << std::endl;
	std::cout <<"The last element of updates queue is " << queue.Back() << std::endl;
	std::cout <<"The size of the upadted queue is " << queue.get_size() << std::endl;



	return 0;
}