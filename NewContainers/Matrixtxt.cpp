#include <iostream>
#include <fstream>

int main(int argc, char** argv)
{
	std::fstream aFile;
	aFile.open("Matrix.txt", std::ios::out);
	if (aFile.is_open())
	{

		aFile <<" <<#include <iostream>\n";

		aFile << "class Matrix\n";
		aFile <<     "{\n";

		aFile << " private:\n";
		aFile    << "int** array;\n";
		aFile    << "  int rows;\n";
		aFile     << " int columns;\n";
		aFile  << "public:\n";
		aFile << "Matrix() {\n";
		aFile << "std::cout << ''2D Matrix is created : '' << std::endl;\n";
		aFile << " }\n";
		aFile << "Matrix(int rows, int columns)\n";
		aFile << "{\n";
		aFile << " this->rows = rows;\n";
		aFile << " this->columns = columns;\n";

		aFile << " array = new int* [rows];\n";
		aFile << "for (int i = 0; i < rows; ++i)\n";
		aFile << "{\n";
		aFile << "array[i] = new int[columns]; \n";
		aFile << "{\n";
		aFile << " for (int j = 0; j < columns; ++j)\n";
		aFile << "{\n";
		aFile << " array[i][j] = 20 + rand() % 310;\n";
		aFile << "	}\n";
		aFile << "}\n";
		aFile << "}\n";
		aFile << "}\n";
		aFile << "void check_size(int rows, int columns)\n";
			aFile << "{\n";

			aFile << "if (rows <= 0 || columns <= 0)\n";
			aFile << "{\n";
			aFile << "<< std::cout << std::endl << ''The size of the rows and columns can't be under 0!!!'';\n";
			aFile << "exit(1);\n";
			aFile << " }\n";

			aFile << " }\n";

			aFile << "~Matrix()\n";
				aFile << "{\n";
				aFile << "std::cout << ''Destructor is called : _ '';\n";
				aFile << "Delete(rows, columns);\n";
				aFile << "}\n";

				aFile << "int main (int argc, char** argv)\n";
				aFile << "{\n";
				aFile<<"//Implementation\n";
				aFile << "return 0;\n";





		aFile.close();
	}



  return 0;
}