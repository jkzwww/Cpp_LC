
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void heap(){

    // allocation (alloc memory for int on heap & return ptr to memory)
    int* pHeapInt = new int; 

    // assignment
    *pHeapInt = 10; 
    
    // free memory on heap (fail to dealloc cuz memory leak)
    delete pHeapInt; 

    // nullify pointer
    pHeapInt = NULL; 

    // heap allow dynamic memory allocation (at runtime)
    int* foo;
    foo = new int[5];
    // ways to access foo
    *foo = 8;
    *(foo+1) = 32;
    foo[2] = 64;

    delete[] foo; //delete array

    // nothrow check(return nullptr instead of throwing exception)
    int* x;
    x = new(nothrow) int[5];
    if(x == nullptr){
        // fails to allocate memory
    }

    delete[] x;
}


//dynamic memory function
int main ()
{
  int i,n;
  int* p;
  cout << "How many numbers would you like to type? ";
  cin >> n;
  p= new (nothrow) int[n];
  if (p == nullptr)
    cout << "Error: memory could not be allocated";
  else
  {
    for (i=0; i<n; i++)
    {
      cout << "Enter number: ";
      cin >> p[i];
    }
    cout << "You have entered: ";
    for (i=0; i<n; i++)
      cout << p[i] << ", ";
      
    delete[] p;
  }
  return 0;
}