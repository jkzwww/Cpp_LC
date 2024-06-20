#include <iostream>
using namespace std;

//class
class Rectangle 
{
  private:
    int width, height;
  public:
    Rectangle(int,int);
    int area() {return width*height;}
};

// constructor
Rectangle::Rectangle(int a, int b) //constructor initialize value
{
  width = a;
  height = b;
}

int main () {
  Rectangle rect (3,4); //used for new object,never return values
  Rectangle rectb (5,6);
  cout << "rect area: " << rect.area() << endl;
  cout << "rectb area: " << rectb.area() << endl;
  return 0;
}


//other ways to call
//  Circle foo (10.0);   // functional form
//  Circle bar = 20.0;   // assignment init.
//  Circle baz {30.0};   // uniform init.
//  Circle qux = {40.0}; // POD-like
