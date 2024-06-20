
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//function(returns a type of data)
int mymodulus(int a, int b)
{
    int r = a % b;
	return r;
}

//void function (returns nothing)
void welcome()
{
    cout << " Welcome, we're open today!!\n";
}


// casting
// static_cast <new_type> (expression)
float fPi = 3.14159f;
// Store a rounded value in another variable
int roughenuf= static_cast<int>(fPi);

// lambda function
/*
[capture list] (parameter list) -> return_type {
    // function body
}
[=] capture by value (copy, ath the time lambda func created)
[&] capture by ref (access, change reflected)
[a, &b] capture a by value and b by reference

*/
void lamda_func(){
	int x = 3;
	int y = 5;

	x = 10;
	y = 35;

	auto print_val = [x](){ cout << x; }; 
	auto print_ref = [&x](){ cout << x; };
	auto modify_ref = [&x]() { x = 25; };
	auto modify_val = [x]() mutable{ x = 50; cout <<"x in mutable lambda: " << x;};

	auto print_all_val = [=]() { cout << x << " & " << y; };
	auto print_all_ref = [&]() { cout << x << " & " << y;};
	
	auto add = [](int a, int b)-> int{ return a+b;};
	cout << add(3,4);

	// to be used iteratively
	auto print_elem = [](int elem){ cout << elem;};
	std::vector<int> vec = {10, 20, 30, 40, 50};
    std::for_each(vec.begin(), vec.end(), print_elem);

}


/*
IO program
*/

int main()
{
	welcome();

	time_t now = time(0);
	char* time_str = ctime(&now);
	cout << "The local date and time is: " << time_str << endl;

	int userNo;
	std::cout << "Enter your queue number: ";
	std::cin >> userNo;
	cout << "User " << userNo << endl; 

	char first[25],last[25];
	cout << "Enter your first name followed by your surname: " ;
	cin.ignore(256,'\n'); // ignore \n ftom cin buffer
	cin.get(first,2);
	cin.ignore(256,' '); // ignore until space
	cin.get(last,2);      // get one character
	cout << "Your initials are " << first << last << '\n';

    char ptname[25];
    cout << "Enter your pet's name: ";
	cin.ignore(256,'\n');
    cin.get(ptname,25);

	std::string condition;
    std::cout << "Enter issue briefly: " << std::flush;
	cin.ignore(256,'\n');
    std::getline(std::cin,condition);
	cout << ptname << " added to waiting room.\n";

	// tn structure
	time_t now = time(0);
	tm *ltm = localtime(&now);
	
	int randno = rand();
	int wait_time = mymodulus(randno,60);
	int min = 30+ltm->tm_min + wait_time;
	int hr = ltm->tm_hour;
	if(min > 60){
		min %= 60;
		hr++;
	}
	hr = mymodulus(hr,24);
	
	cout << "Estimated service time: "<< hr << ":" << min << endl;


    return 0;
}
