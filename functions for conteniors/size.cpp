#include <iostream>

void Memory(int* arr, size_t size );


int main(int argc, char** argv)
{
	
	int array[6] = { 1,2,3,4,5,7 };


	std::cout << "the size of the array is " << sizeof(array) << std::endl;
	Memory(array, sizeof(array));

	return 0;
}

void Memory(int* arr, size_t size)
{
	std::cout << "The size of the array is " << size << std::endl;
}