#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "HashTable.h"

// hash function
// add up all char values in input c-string
// and modulo by TABLE_SIZE
// (return int in range of 0 to TABLE_SIZE-1)
template<int TABLE_SIZE>
int myHashfunc(const char* input)
{
	int output = 0;
	for (int i = 0; i < strlen(input); i++)
		output += (int)input[i];
	return output % TABLE_SIZE;
}

int main()
{


	// test set
	std::ifstream testfile;
	char filepath[1000];
	std::vector<std::string> lines;

	std::cout << "enter path to test file (text file with newline as delimiter):  ";
	std::cin >> filepath;
	testfile.open(filepath);
	if (!testfile.good())
	{
		std::cout << "error: unable to open file.";
		std::cout << "enter path to test file: ";
		std::cin >> filepath;
	}
	char line[1000];
	int i = 0;
	while (testfile.getline(line, 1000))
	{
		std::cout
			<< "[" << i++ << "]: "
			<< line << '\n';
		lines.push_back(std::string(line));
	}

	// chained hashtable test
	HashTable_Chain foo_chain(myHashfunc<16>, 16);
	// linear probing hashtable test
	 HashTable_LinProbe foo_lin(myHashfunc<32>, 32);

	// add test set into hashtables
	for (std::string line : lines)
	{
		foo_chain.add(line.c_str());
		foo_lin.add(line.c_str());
	}
	
	foo_chain.print();
	foo_lin.print();


}