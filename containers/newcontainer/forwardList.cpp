#include <iostream>
template <typename T>

struct Node
{
	T data;
	Node* next=nullptr;

public:
	Node(int data) :data(data), next(nullptr) {};
	~Node() = default;

};
template <typename T>

class ForwardList
{
	Node<T>* head = nullptr;
public:
	ForwardList() :head(nullptr) {};
	~ForwardListt() = default;
public:
	void pushFront(T val)
	{
		Node<T>* temp = new Node<T>(val);
		temp->next = head;
		head = temp;
	}
	void popFront()
	{
		if (head == nullptr)
		{
			std::cout << "List is empty" << std::endl;
			return;
		}
		Node<T>* temp = head;
		head = temp->next;
		delete temp;
		
	}
	void erece()
	{
		if (head == nullptr)
		{
			std::cout << "List is empty " << std::endl;
		}
		while (head != nullptr)
		{
			Node<T>* temp = head;
			head = head->next;
			delete temp;
		}
	}

	void reverce()
	{
		std::stack<Node<T>*>st;
		Node<T>* temp = head;
		while (temp != nullptr)
		{
			st.push(temp);
			temp = temp -> next;
		}
		
		head = st.top();
		temp = head;
		st.pop();
		while (!st.empty())
		{
			temp->next = st.top();
			st.pop();
			temp = temp->next;

		}
		temp->next = nullptr;
	}
	T find_n_end(int n)
	{
		Node<T>* temp1 = head;
		Node<T>* temp2 = head;
		int count = 0;
		while (temp1 != nullptr)
		{
			count++;
			temp1 = temp1->next;
			if (count >= n)
			{
				temp2 = temp2->next;
			}

			if (count < n)
			{
				std::cout << "Not enough elements \n";
			}
		}
		return temp2->data;

	}

	bool is_cycle()
	{
		Node<T>* temp1 = head;
		Node<T>* temp2 = head;
		if (temp2 == nullptr || temp2->next == nullptr)
		{
			return false;
		}


		while (temp2 != nullptr && temp2->next != nullptr)
		{
			temp1 = temp1->next;
			temp2 = temp2->next->next;
			if (temp1 == temp2)
			{
				return true;
			}
		}


		return false;

	}
	
};

int main(int argc, char** argv)
{
	ForwardList<int> list;
	list.pushFront(10);
	list.pushFront(15);

	return 0;

}