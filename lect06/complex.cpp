//Lecture 6: 
/*
1. Automate compiling C++ programs
2. Why did we get three calls to the constructor and 4 to the destructor
*/

#include <iostream>
#include <cmath>
using namespace std;
class Complex{
    private: 
        //member variables 
        double real;
        double imag;
    public:
        //constructor: same name as the class, no return type, default provided by C++
        /*Complex(){
            real = imag = 0;
        }*/

        // Parameterized constructor with default values, called right AFTER an  an object of Complex is created in memory (stack or heap)
        Complex(double re = 0, double im = 0){
            cout<<"Inside the constructor"<<endl;
            real= re;
            imag = im;
        }
        // default destructor provided by c++
        // called right BEFORE an object of Complex is deleted from memory (stack or heap)
        ~Complex(){
            cout<<"Inside the destructor"<<endl;
        }
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
            if(imag>=0){
                cout<<real<< "+"<<imag<<"j"<<endl;
            }else if(imag < 0){
                cout<<real<< "-"<<-imag<<"j"<<endl;
            }
            
        }
     //setters: modify the object    
        void conjugate(){
            //conjugate of a+jb is a-jb
            imag = -1*imag;

        }
        void setReal(double r){
            // real is implicit object's real member variable
            // r is just a parameter   
            real = r;
        }
        void setImag(double r){
            // imag is implicit object's imag member variable
            // r is just a parameter   
            imag = r;
        }
 
      //Don't return the result by reference because....result is a local variable
        Complex operator+(Complex& other){
            //cout<<"Inside the operator + function"<<endl;
            Complex result;
            result.real = real + other.real;
            result.imag = imag + other.imag;
            //cout<<"Returning from operator +"<<endl;
            return result;
        }
        //C++ default copy constructor
        Complex(const Complex& other){
            this->real = other.real;
            this->imag = other.imag;
            cout<<"inside copy constructor"<<endl;
        }

        //Assignment operator (C++ provides a default version)
        Complex& operator=(const Complex other){
            real = other.real;
            imag = other.imag;
            cout<<"inside copy assignment"<<endl;
            return *this;

        }
     
};
//cout<<x;
//Complex data = x; // copy constructor
ostream& operator<<(ostream& out, Complex& data){
    data.print();
    return out;
}
//cout<<c1; operator<<(cout, c1);
//(cout<<c1)<<endl; // (a + b) + c
//cout<<endl;

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