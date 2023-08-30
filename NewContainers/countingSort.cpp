#include <iostream>
#include <vector>


void countingSort(std::vector<int>& samp)
{
	int s = samp.size();

	int max = samp[0];
	int min = samp[0];
	for (int i = 1; i < s; ++i)
	{
		if (samp[i] > max)
			max = samp[i];
	}
	for (int i = 1; i < s; ++i)
	{
		if (samp[i] <  min)
			min = samp[i];
	}
	int range = max - min+1;
	std::vector<int>count(range, 0);
	std::vector<int>final(s);

	for (int occ : samp)
	{
		count[occ - min]++;
	}
	for (int i = 1; i < range; ++i) {
		count[i] += count[i - 1];
	}
	for (int i = s - 1; i >= 0; --i) {
		final[count[samp[i] - min] - 1] = samp[i];
		count[samp[i] - min]--;
	}

	samp = final;
}

int main(int argc, char** argv)
{
	std::vector<int> vec = { 4, 2, 2, 8, 3, 3, 1 };

	countingSort(vec);

	std::cout << "Sorted array: ";
	for (int element : vec) {
		std::cout << element << " ";
	}
	std::cout << std::endl;




	return 0;
}