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
	~Node(){}
	

};

template <typename T>
class List:public Node<T>
{
	Node<T>* head;
	Node<T>* tail;
public:
	List()
	{
		head = nullptr;
		tail = nullptr;
	}
	~List(){}
	
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
		}
	}
	void PrintForward()
	{
		Node<T>* traverser = head;
		while (traverser != nullptr)
		{
			std::cout << traverser->data <<' ';
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
};
int main(int argc, char** argv)
{
	List<int> list;
	list.InsertElement(15);
	list.InsertElement(20);
	list.InsertElement(2);
	list.PrintForward();
	std::cout << std::endl;
	list.PrintBackward();
	std::cout << std::endl;


}