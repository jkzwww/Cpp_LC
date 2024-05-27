
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
using namespace std;

//function(returns a type of data)
int mymodulus(int a, int b)
{
    int r;
    r = a % b;

    return(r);
}

//void function (returns nothing)
void welcome()
{
    cout << " Welcome, we're open today!!\n";
	
	time_t now = time(0);
	char* time_str = ctime(&now);

	cout << "The local date and time is: " << time_str << endl;
}


int main()
{
	welcome();

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

// casting
// static_cast <new_type> (expression)
float fPi = 3.14159f;
// Store a rounded value in another variable
int roughEnough = static_cast<int>(fPi);

// lambda function
/*
[capture list] (parameter list) -> return_type {
    // function body
}
[=] capture by value (copy)
[&] capture by ref (access)
[a, &b] capture a by value and b by reference
*/

auto add = [](int a, int b)-> int{ return a+b;};

auto print_elem = [](int elem){ cout << elem;};

// untie to optimize performance
int main_comp(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int a, b;
    cin >> a >> b;
    cout << a + b << "\n";

	return 0;
}

