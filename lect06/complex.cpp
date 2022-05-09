//Lecture 6: 
/*
1. Automate compiling C++ programs
2. Why did we get three calls to the constructor and 4 to the destructor
*/

#include <iostream>
#include <cmath>
#include "complex.h"
using namespace std;

//What's a good way of initializing objects of the class? By implementing a constructor
int main(int argc, char const *argv[])
{
    Complex c(10, 10); // c is an object of type Complex or c is an instance of complex
    // c.real and c.imag  are some random value
    // c++ does NOT automatically initial variables 
    // constructor for Complex is called
    Complex m {20, 20}; //C++ 11 notation

    cout<<"c = c + m;"<<endl;
    m = c = c + m; // c.operator+(m) and copy assignment operator
    //cout<<c<<m<<endl;

    cout<<"Complex x = c;"<<endl;
    Complex x = c; // calls copy constructor

    cout<<"cout << x ;"<<endl;
    cout << x ; // cout is an object of  ostream, 
                // x is an object of type Complex
                // Compiler decides which implementation of << to call based on type of operands
 
    /*
    Complex* c1 = new Complex{20, 40}; //calls constructor
    cout<<"c1: "<<*c1<<endl; // 20+40j
    //cout<<endl;
    Complex c3(*c1); //Calls the copy constructor 
    cout<<"c3: "<<c3;//20+40j
    cout<<endl;
    Complex c4(c);
    cout<<"c4: "<<c4<<endl; //10+10j
    delete c1; //calls destructor
    */
    //Several calls to destructor to remove stack objects c, m, x, c3, c4
    return 0;
}


// Adding two complex numbers together