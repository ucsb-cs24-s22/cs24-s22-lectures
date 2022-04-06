//Lecture 4: Object Oriented Programming
// Objects are central to how we organize or think about code.
// - Code objects by their attributes and behavior 
// Example: Complex numbers  a + jb, j = sqrt(-1)
// hide information 

#include <iostream>
#include <cmath>
using namespace std;
class Complex{
    private: 
        //member variables 
        double real;
        double imag;
    public:
    //member functions
    //getters or accessors (compute or return some data) but they don't modify the object
        double getMagnitude() const{
            //keyword const says the functions will not modify any of the member variables
            //real = 5;
            return sqrt(real*real + imag*imag);
        }
        double getReal() const{
            return real;
        }

        double getImaginary() const{
            return imag;
        }

        void print() const{
            cout<<real<< "+ j"<<imag<<endl;
        }
     //setters: modify the object    
        void conjugate(){
            //conjugate of a+jb is a-jb
            imag = -1*imag;

        }
        void setReal(double r){
            // implicit object's real member variable
            // r is just a parameter   
            real = r;
        }
        void setImag(double r){
            // implicit object's real member variable
            // r is just a parameter   
            imag = r;
        }
        //What is the type of the parameter passed into add function?
        //What is the return type?
        Complex operator+(Complex other){
            Complex result;
            result.real = real + other.real;
            result.imag = imag + other.imag;
            return result;
        }
        
};

void operator<<(ostream& out, Complex data){
    data.print();
}
//What's a good way of initializing objects of the class?
int main(int argc, char const *argv[])
{
    Complex c; // c is an object of type Complex or c is an instance of complex
    // c.real = ? c.imag = ? (are some random value)
    // c++ does not automatically initial variables for us including objects
    c.setReal(10); //10+j?
    c.setImag(10);
    cout<<c.getReal()<<endl; // always 10
    //c.real = 0; // Not allowed by the compiler because real and imag are private members
    //c.imag = 0;
    cout<<c.getMagnitude()<<endl; //10

    Complex m;
    m.setReal(20); //10+j?
    m.setImag(20);

    //Complex x = c.add(m); //
    Complex x = c + m; // c.opertaor+(m)
    //x.print();
    cout << x ; // cout is an object of class ostream, x is an object of type Complex
    //cout.operator<<(x); //Not allowed!
    //operator<<(cout, x);


    return 0;
}


// Adding two complex numbers together