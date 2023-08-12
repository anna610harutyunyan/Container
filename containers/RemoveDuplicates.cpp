#include <iostream>
#include<vector>
#include <set>

void Print(std::vector<int> const& vec);

int main(int argc, char** argv)
{
	std::vector<int>vec = { 15,25,15,25,69,1,69,7,1,1,100,125,125,300,100 };
	std::cout << "The elements of vector are \n";

	Print(vec);
	std::cout << std::endl;
	std::cout << std::endl;

	std::set<int, std::less<int>>set;

	for (int i = 0; i < vec.size(); ++i)
	{
		int num = vec[i];
		set.insert(num);
	}

	std::cout << "The elements of set are \n";


	for (int num : set)
	{
		std::cout << num << ' ';
	}
	std::cout << std::endl;
	std::cout << std::endl;

	return   0;

}
void Print(std::vector<int> const& vec)
{
	for (int i = 0; i < vec.size(); ++i)
	{
		std::cout << vec[i] << ' ';
	}
}
