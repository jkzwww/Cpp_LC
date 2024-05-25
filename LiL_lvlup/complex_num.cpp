#include "complex_num.h"

complex_num::complex_num(double r, double i){   
    a = r;
    b = i;
}

complex_num complex_num::operator +(complex_num w){
    complex_num z;
    z.a = a + w.a;
    z.b = b + w.b;
    return z;
}

complex_num complex_num::operator -(complex_num w){
    complex_num z;
    z.a = a - w.a;
    z.b = b - w.b;
    return z;
}

complex_num complex_num::operator *(complex_num w){
    complex_num z;
    z.a = a*w.a - b*w.b;
    z.b = a*w.b + b*w.a;
    return z;
}

complex_num complex_num::operator /(complex_num w){
    complex_num z;
    z.a = (a*w.a + b*w.b) / (w.a*w.a + w.b*w.b);
    z.b = (b*w.a - a*w.b) / (w.a*w.a + w.b*w.b);
    return z;
}

void complex_num::print(std::ostream &os){
    std::string sign = (b>=0)? " +":" ";
    std::cout << a << sign << b << "i";
}