#include <iostream>
#include <vector>

void Print(std::vector<int>& samp)
{
	for (auto element : samp)
	{
		std::cout << element << ' ';
	}
	std::cout << std::endl;
}

void Remove(std::vector<int>& samp, int n)
{
	for (auto it = samp.begin(); it != samp.end();)
	{
		if (*it == n)
		{
			it = samp.erase(it);
		}
		else
		{
			std::cout << *it << ' ';
			++it;
		}
	}
}

int main(int argc, char** argv)
{
	std::vector<int>my_vector = { 12,15,25,11,1,3,65,9,78,4,5,23,11,32,58 };
	int n;
	std::cout << "The elements of the vector are_ \n";
	Print(my_vector);
	std::cout << std::endl << "Please, enter the n_ ";
	std::cin >> n;
	std::cout << std::endl << "The elements without n are_\n";
	Remove(my_vector, n);
	return 0;
}