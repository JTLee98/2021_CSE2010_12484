#include "CPP/poly.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>


void testPoly(const char* filepath) 
{
	std::ifstream testf;
	try
	{	
		// open file
		testf.open(filepath);
		if (not testf.is_open())
		{
			std::exception err("ERROR: could not open test file\n");
			throw err;
		}

		int total;
		testf >> total;
		// instantiate polynomials A, B
		Polynomial A, B; 
		// define parse storage variables
		int index = total;
		char OpCode, i_poly = 0;
		int i_coeff = 0;
		unsigned int i_exp = 0;
		char myAns[1024] = "", testAns[1024] = "";
	
		// read & execute test operations

		while (not testf.eof())
		{
			testf >> index >> OpCode;
			switch (OpCode)
			{
			case 'a':
				testf >> i_poly >> i_exp >> i_coeff;
				switch (i_poly)
				{
				case 'A':
					A.addTerm(i_exp, i_coeff);
					break;
				case 'B':
					B.addTerm(i_exp, i_coeff);
					break;
				default: break;
				}
				break;
			case 'p':
				testf >> i_poly;
				switch (i_poly)
				{
				case 'A':
					strcpy_s(myAns, 1024, A.printToBuff()); 
					break;
				case 'B':
					strcpy_s(myAns, 1024, B.printToBuff()); 
					break;
				default: break;
				}

				testf.get(testAns, 1024, '\n');
				if (strcmp(myAns, testAns) != 0)
				{
					std::stringstream errmsg;
					errmsg
						<< "Test failed on case #" << index << '\n'
						<< " - correct  result: " << testAns << '\n'
						<< " - returned result: " << myAns << '\n';
					std::exception err(errmsg.str().c_str());
					throw err;
				}
				break;
			case 'c':
				testf >> i_poly;
				switch (i_poly)
				{
				case 'A':
					A.clear();
					break;
				case 'B':
					B.clear();
					break;
				default: break;
				}
				break;
			case 'm':
				strcpy_s(myAns, 1024, (A * B).printToBuff());
				testf.get(testAns, 1024, '\n');
				if (strcmp(myAns, testAns) != 0)
				{
					std::stringstream errmsg;
					errmsg
						<< "Test failed on case #" << index << '\n'
						<< " - expected result: " << testAns << '\n'
						<< " - returned result: " << myAns << '\n';
					std::exception err(errmsg.str().c_str());
					throw err;
				}
				break;

			default:
				break;
			}
			
		}
	}
	catch (std::exception& err)
	{
		std::cout << err.what() << std::endl;
		return;
	}
	std::cout << "test finished.";
	testf.close();

}



int main()
{
	testPoly("D:/DRIVE/SCHOOL/CSE2010-DataStructs/repos/2021_cse2010_2018014275/Lab4/source/testCases.txt");

	return 0;
}