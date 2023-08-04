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
	Node <T>* topElement;
public:
	SingleLinkedList()
	{
		head = nullptr;
		std::cout << "Call List constructor " << std::endl;
	}
	~SingleLinkedList()
	{
		std::cout << "Call List destructor " << std::endl;
	}
public:
	void insertElement(const T& value)
	{
		Node<T>* newNode = new Node<T>(value);
		newNode->next = head;
		head = newNode;
		topElement = newNode;
		std::cout << "Inserted " << std::endl;

	}
	void removeElement()
	{
		if (head == nullptr)
		{
			std::cout << "There is no element " << std::endl;
		}
		else if (head->next == nullptr)
		{
			delete head;
			head = nullptr;
			std::cout << "The last element is removed " << std::endl;
		}
		else
		{
			Node<T>* temp = head;
			while (temp->next->next != nullptr)
			{
				temp = temp->next;
			}

			Node<T>* last = temp->next;
			temp->next = nullptr;
			delete last;
			topElement = temp;
			std::cout << "The last element is removed " << std::endl;
		}
	}
	const T& Top()
	{
		if (head != nullptr)
		{
			return topElement->data;
		}
		else
		{
			throw std::runtime_error("Stack is empty , there is no top member!! ");
		}
	}
	void Print()
	{
		Node<T>* reversal = head;
		while (reversal != nullptr)
		{
			std::cout << reversal->data <<' ';
			reversal = reversal->next;
		}
	}
};
template <typename T>
class Stack :private SingleLinkedList<T>
{
public:
	using SingleLinkedList<T>::SingleLinkedList;
	Stack() :SingleLinkedList<T>()
	{
		std::cout << "Call Stack constructor " << std::endl;
	}
	~Stack()
	{
		std::cout << "Call Stack destructor " << std::endl;
	}
public:
	void Push(T value)
	{
		SingleLinkedList<T>::insertElement(value);
	}
	void Pop()
	{
		SingleLinkedList<T>::removeElement();
	}
	const T& Top()
	{
		return SingleLinkedList<T>::Top();
	}
	void printStack()
	{
		SingleLinkedList<T>::Print();
	}
};
int main(int argc, char** argv)
{
	Stack<int> stack;
	stack.Push(5);
	stack.Push(3);
	stack.Push(7);
	stack.Push(11);
	stack.Push(9);
	stack.printStack();
	std::cout << std::endl;
	std::cout << "The top element is " << stack.Top() << std::endl;
	stack.Pop();
	stack.Pop();
	stack.printStack();
	std::cout << std::endl;
	std::cout << "The top element of updated stack is " << stack.Top() << std::endl;


	return 0;
}