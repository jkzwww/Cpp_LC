
#include <iostream>
#include <fstream>
//using namespace std

int main()
{
	
	//chap1
	std::cout << "Hello,world!!\n\n\n";

	//chap2

	int userNum = 0, result = 0;
	std::cout << "Enter an integer to be squared: ";
	std::cin >> userNum;
	result = userNum * userNum;
	std::cout << userNum << " squared is " << result;

	return 0;
}
