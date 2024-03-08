//reference

int score = 100;
int& scoreRef = score; //must be initialised

//swapping reference(can refer to main loop value)
void byRefSwap(int& x, int& y)
{
    int temp = x;
    x = y;
    y = temp;
}

//avoid changing ref
const int& myScore = score;

//pointer
int* pScore = &score //store address of score in pointer
 
//pointer can be declared without initialisation
int * pScore = NULL;
int * pScore = 0;
int * pScore = nullptr;

//derefencing (print value or else will print address)
cout << *pScore;

//changing value
pScore += 500; //change address 
*pScore += 500; //change value

//constant pointer
int* const pScore = &score; //const location
const int* pScore = &score; //const value pointed

const int* const pScore = &score; //const location and value

//object pointer  (for classes created manually)
player rei();
player* pRei = &rei;

//diff deref way
cout << (*pRei).GetName();

cout << pRei -> GetName(); //member access operator arrow


//pointer function
void pointerSwap(int* x, int* y) //swap values pointed
{
	int temp = *x;  //remember to deref when changing value
	*x = *y;
	*y = temp;
}

void pointerSwap(int*& x, int*& y) //swap addresss pointed
{
	int* temp = x;
	x = y;
	y = temp;
}

//heap
int* pHeapInt = new int; //int(10)
*pHeapInt = 10; 

delete pHeapInt; //delete thing pointed to

pHeapInt = NULL; //set pointer to null


//pointer for array
int numbers[5];
int * p;
p = numbers;  *p = 10;
p++;  *p = 20;
p = &numbers[2];  *p = 30;
p = numbers + 3;  *p = 40;
p = numbers;  *(p+4) = 50;


//pointer increment
*p++   // same as *(p++): increment pointer, and dereference unincremented address
*++p   // same as *(++p): increment pointer, and dereference incremented address
++*p   // same as ++(*p): dereference pointer, and increment the value it points to
(*p)++ // dereference pointer, and post-increment the value it points to 


//function as another function argument(pointer)
// pointer to functions
#include <iostream>
using namespace std;

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


//dynamic memory
int* foo;
foo = new int[5];
*foo = 8;
*(foo+1) = 32;
foo[2] = 64;


//nothrow check allocation
int * foo;
foo = new (nothrow) int [5];
if (foo == nullptr)
{
  // error assigning memory. Take measures.
}

//new operator
int* pPon;
pPon = new char; //single element
pPonde = new char [9]; //array

//delete operator
delete pPon;
delete[] pPonde;


//dynamic memory function
int main ()
{
  int i,n;
  int * p;
  cout << "How many numbers would you like to type? ";
  cin >> i;
  p= new (nothrow) int[i];
  if (p == nullptr)
    cout << "Error: memory could not be allocated";
  else
  {
    for (n=0; n<i; n++)
    {
      cout << "Enter number: ";
      cin >> p[n];
    }
    cout << "You have entered: ";
    for (n=0; n<i; n++)
      cout << p[n] << ", ";
    delete[] p;
  }
  return 0;
}
