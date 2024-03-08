#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//writing file
int main() 
{
    ofstream fid ("example.txt");
    if (fid.is_open()) {
        fid << "First line.\n";
        fid.close();
    }

    else cout << "Unable to open file";
    
    return 0;
}

//reading file 

int main() 
{

    string line;
    ifstream fid ("example.txt");

    if (fid.is_open() ) //check
    {
        while ( getline (fid,line))
        {
            cout << line << '\n';
        }
        fid.close();
    }

    else cout <<"Unable to open file";
    
    return 0;

}

//reading and calculation
int main() 
{

	int fnum1 = 0, fnum2 = 0, result = 0;
	fstream fid;
	fid.open("numbers.txt");
	fid >> fnum1;
	fid >> fnum2;
	fid.close();
	result = fnum1 * fnum2;
	cout << "the numbers multiplied is " << result;
}


//function(returns a type of data)
int modulus(int a, int b)
{
    int r;
    r = a % b;

    return(r);
}

int main() 
{
    int a, b, z;
    cout << "Enter numerator:";
    cin >> a;
    cout << "Enter denominator:";
    cin >> b;

    z = modulus(a, b);

    cout << "The remainder is " << z << "\n";

    return 0;
}

//void function (returns nothing)

void welcome()
{
    cout << " We're open today!!";
}

int main() {

    welcome();

    return 0;
}

//get
int main()
{
    char name[25];

    cout << "Enter your pet's name: ";
    cin.get(name,25);
    cout << "Hope " << name << " is happy and healthy!\n\n";

    return 0;
}

//ignore 
int main () 
{
  char first, last;

  cout << "Please, enter your first name followed by your surname: ";

  first = cin.get();     // get one character
  cin.ignore(256,' ');   // ignore until space

  last = cin.get();      // get one character

  cout << "Your initials are " << first << last << '\n';

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

