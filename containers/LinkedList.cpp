#include <iostream>
template <typename T>


struct Node
{
	T data;
	Node* next;
	Node()
	{
		data = 0;
		next = nullptr;
	}
	Node(T value) :data(value), next(nullptr) {};
	~Node()
	{
		delete next;
	}
};
template <typename T>

class SingleLinkedList
{
	Node <T>* head;
public:
	SingleLinkedList()
	{
		head = nullptr;
	}
	~SingleLinkedList()
	{
		delete head;
	}
public:
	void insertElement(const T& value)
	{
		Node<T>* newNode = new Node<T>(value);
		newNode->next = head;
		head = newNode;
		std::cout << "Inserted " << std::endl;
		
	}
};
int main(int argc, char** argv)
{
	SingleLinkedList<int> list;
	list.insertElement(10);
	list.insertElement(15);

}