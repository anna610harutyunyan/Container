#include <iostream>
#include <string>
#include <map>

int main(int argc, char** argv)
{
	std::map<std::string, std::string> capitalCity;
	capitalCity.insert(std::pair<std::string, std::string>("Armenia", "Yerevan"));
	capitalCity.insert(std::pair<std::string, std::string>("France", "Paris"));
	capitalCity.insert(std::pair<std::string, std::string>("USA", "Vashington"));
	capitalCity.insert(std::pair<std::string, std::string>("Spain", "Madrid"));
	capitalCity.insert(std::pair<std::string, std::string>("Italy", "Rome"));
	capitalCity.insert(std::pair<std::string, std::string>("Russia", "Moscow"));
	capitalCity.insert(std::pair<std::string, std::string>("Great Britan", "London"));
	capitalCity.insert(std::pair<std::string, std::string>("Japan", "Tokyo"));
	capitalCity.insert(std::pair<std::string, std::string>("China", "Beijing"));
	capitalCity.insert(std::pair<std::string, std::string>("Estonia", "Tallinn"));

	for (auto pair : capitalCity)
	{
		std::cout << pair.first << " - " << pair.second << std::endl;
	}

	std::cout << "Our map consist of " << capitalCity.size() << " Key-Value pairs \n";

	return 0;
}