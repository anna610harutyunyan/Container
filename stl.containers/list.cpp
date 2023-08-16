#include <iostream>
#include <list>

void remove(std::list<int>& samp, int n)
{
	for (std::list<int>::iterator it = samp.begin(); it != samp.end();)
	{
		
		if (*it == n)
		{
			it=samp.erase(it);
		}
		else
		{
			std::cout << *it << ' ';
			++it;
		}
	}
}
void Print(std::list<int>& samp)
{
	for (auto element : samp)
	{
		std::cout << element << ' ';
	}
	std::cout << std::endl;
}
int main(int argc, char** argv)
{
	std::list<int>my_list = { 15,75,3,4,6,14,58,9,6,77,45,67,89,11,1 };
	int n;
	Print(my_list);
	std::cout << std::endl;
	std::cout << "Please enter the n_ ";
	std::cin >> n;
	std::cout << std::endl;
	std::cout << "The memebers without n are \n";
	remove(my_list, n);




	return 0;
}

