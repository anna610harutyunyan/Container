#include <iostream>
#include <list>
#include<algorithm>


int main(int argc, char** argv)
{
	std::list<int>list = { 122,12,58,455,322,15,133,199,200,658,125,320,156 };

	std::for_each(list.begin(), list.end(), [](int& element) { (element > 100 && element < 200) ? std::cout << element << ' ' : std::cout; });

	return 0;
}