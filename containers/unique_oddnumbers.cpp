#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <set>
void printVector(std::vector<int> const& rand_numbers);
void evenNumber(std::vector<int>& rand_numbers);
void printSet(std::set<int, std::greater<int>>& Set);


int main(int argc, char** argv)
{
	srand(time(0));
	std::vector <int>rand_numbers = { rand() % 100,rand() % 100,rand() % 100,rand() % 100,rand() % 100,rand() % 100,rand() % 100,rand() % 100,rand() % 100 };
	std::cout << "The members of the vector are \n";
	printVector(rand_numbers);
	std::cout << std::endl;
	std::cout << "The  vector wihout odd numbers is \n";
	evenNumber(rand_numbers);
	printVector(rand_numbers);

	std::cout << std::endl;
	std::set<int, std::greater<int>> Set;
	for (int i = 0; i < rand_numbers.size(); ++i)
	{
		int num = rand_numbers[i];
		Set.insert(num);
	}
	std::cout << "The sorted unique elements of the vectore are \n";
	printSet(Set);
	std::cout << std::endl;


	return 0;
}

void printVector(std::vector<int> const& rand_numbers)
{
	for (int i = 0; i < rand_numbers.size(); ++i)
	{
		std::cout <<rand_numbers[i] << ' ';
	}
}
void evenNumber(std::vector<int>& rand_numbers)
{
	for (std::vector<int>::iterator ptr=rand_numbers.begin(); ptr!=rand_numbers.end();)
	{
		if (*ptr % 2 != 0)
		{
			ptr=rand_numbers.erase(ptr);
		}
		else
		{
			++ptr;
		}
	}
}
void printSet(std::set<int, std::greater<int>>& Set)
{
	for (int num : Set)
	{
		std::cout << num << ' ';
	}
}