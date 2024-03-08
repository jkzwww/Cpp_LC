#include <iostream>
#include <string>
#include <math.h>

using std::cin;
using std::cout;
using std::endl;

//recursive function
long factorial (long a)
{
  if (a > 1)
   return (a * factorial (a-1));
  else
   return 1;
}

// Returns the sum of the first n even numbers' squares
int evenSquares(int n){
	
	// stop recursion when n is 0
	if(n == 0){
		return n;
	// check if n is even
	} else if(n % 2 == 0){
		// sum of even numbers squares
		return n*n + evenSquares(n-1);
	} else {
		// if number is off - do nothing and call function again
		return evenSquares(n-1);
	}
}

// return true if string s with the lenght l contains char c - otherwise false
bool linear(std::string s, char c, int l){

	// Do linear search from back to front
	if(l < 0){
		return false;
	// if string index == char - return true
	} else if(s[l] == c){
		return true;
	// repeat linear search and decrement index
	} else {
		return linear(s, c, l-1);
	}
}

// return nth fibonacci number
int FibonacciSeq(int n){
  if(n > 1){
    return FibonacciSeq(n-1) + FibonacciSeq(n-2); 
  }
  else{
    return n;
  }
}


int main ()
{
  long number = 9;
  cout << number << "! = " << factorial (number) << endl;

  int sumOfEvenSquares = evenSquares(5);
  cout << "Even squares: " << sumOfEvenSquares << endl;

  std::string hello = "Hello";
	char substring = 'e';
	bool containsString = linear(hello, substring, hello.length()-1);
  cout << "Char is in string: " << containsString << endl;

  int FibNo = 10;
  cout << FibNo << "th Fibonacci number = " << FibonacciSeq(FibNo) << endl;
  return 0;
}
