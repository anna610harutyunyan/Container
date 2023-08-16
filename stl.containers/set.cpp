#include <iostream>
#include <set>

void Print(std::set<int>& samp)
{
	for (auto element : samp)
	{
		std::cout << element << ' ';
	}
	std::cout << std::endl;
}
void Remove(std::set<int>& samp, int n)
{
	for (std::set<int>::iterator it = samp.begin(); it != samp.end();)
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
	std::set<int>my_set = { 12,25,33,1,58,12,69,87,55,5,3,11,2,4,589 };
	int n;
	std::cout << "The elements of the set are_ \n";
	Print(my_set);
	std::cout  <<std::endl <<"Please, enter the n_";
	std::cin >> n;
	std::cout << std::endl << "The elements except n are_ \n";
	Remove(my_set, n);

	return 0;
}