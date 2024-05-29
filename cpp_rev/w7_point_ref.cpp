
#include <iostream>
#include <string>
#include <vector>

using namespace std;
//reference
void references(){
  // alternative name for existing variable
  int var = 100;
  int& ref = var; // ref can never be void
    
  //refer to var without allowing modif through refB
  // read only access
  const int& refB = var;

  /*
    - modify passed parameters through ref
    - avoid copy of large structures
    - in for loop to modify stuff (avoid copy)
  */
}


void pointer_basics(){

  int var = 35;

  // null pointers (uninitialised)
  int* ptrA = nullptr; // =0 ; =NULL

  // initialise pointer (store address)
  int* ptr = &var; 

  // update values
  *ptr += 17;
    
  // dereferencing(get val at ptr)
  std::cout << "pointer value: " << *ptr << endl;

  //constant pointers
  int* const ptrC = &var; //const location
  const int* ptrD = &var; //const value pointed
  const int* const ptrE = &var; //const location and value

  //pointer increment
  int* p = &var;
  *p++;   // same as *(p++): increment pointer, and dereference unincremented address
  *++p;   // same as *(++p): increment pointer, and dereference incremented address
  ++*p;   // same as ++(*p): dereference pointer, and increment the value it points to
  (*p)++; // dereference pointer, and post-increment the value it points to 


}

//pointer function
// pass by reference with pointer arguments
void swapVal(int* x, int* y) //swap values pointed
{
	int temp = *x;  //remember to deref when changing value
	*x = *y;
	*y = temp;
}

// pass by reference with reference arguments
void byRefSwap(int& x, int& y)
{   
    int temp = x; // dont need deref, implicit deref
    x = y;
    y = temp;
}

void swapAddr(int*& x, int*& y) //swap addresss pointed
{
	int* temp = x;
	x = y;
	y = temp;
}

class Player 
{
  private:
    int id;
    string name;
  public:
    Player(int i=0, string x="XXX"): id(i), name(x){}
    void shout(){std::cout << "Player#" << id << " " << name << endl;}
};

void class_ptrs(){
  // object pointers
  Player rei(0,"ayanami");
  Player* ptrRei = &rei;

  // deref
  (*ptrRei).shout();

  // direct pointer call member functions 
  ptrRei->shout();

}

void array_ptr(){

  int numbers[5];
  int* p;
  p = numbers;  *p = 10;
  p++;  *p = 20;
  p = &numbers[2];  *p = 30;
  p = numbers + 3;  *p = 40;
  p = numbers;  *(p+4) = 50;

  int val[3];
  // array itself is address to 1st elem
  // val = &val[0]
  // val[0] = *val

  //2d array
  // nums[ i ][ j ] is equivalent to *(*(nums+i)+j)
  int nums[2][3]  =  { { 16, 18, 20 }, { 25, 26, 27 } };

  int no = *(*nums+1)+2;
  cout << no << "is the elem at nums[1][2]";

  // pointer pointer
  char a;
  char* b;
  char** c;
  a = 's';
  b = &a;
  c = &b;

}

//function as another function argument(pointer)
// pointer to functions
int addition (int a, int b)
{ return (a+b); }

int subtraction (int a, int b)
{ return (a-b); }

int operation (int x, int y, int (*functocall)(int,int))
{
  int g;
  g = (*functocall)(x,y);
  return (g);
}

int main ()
{
  int m,n;
  int (*minus)(int,int) = subtraction;

  m = operation (7, 5, addition);
  n = operation (20, m, minus);
  cout <<n;
  return 0;
}

