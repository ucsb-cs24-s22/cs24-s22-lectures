//stl.cpp
//STL: standard template library

#include<set>
#include<vector>
#include <iostream>
#include "complex.h"
using namespace std;
// How should we modify the function inorder to pass in parameters that are any iterable 
// type, like array, set or vector?
template <class T>
void print(T& s){
    for(auto item: s){ //inorder traversal of the bst 
        cout<<item<<endl;
    }
}

int main(){
    vector<Complex> v { Complex(20, 10), Complex(10, 20), Complex(30, 40), Complex(50, 60), Complex(70, 80), Complex(90, 100)};
    set<Complex> bst1; // BALANCED BST
    set<string> bst2 {"Vaishali", "Diba", "Victor"};

    for(auto item: v){
        bst1.insert(item);
    }
    // height of bst if set was a regular bst: 10 , height n
    // but actually set is a balanced bst and so height = O(log n) 
    // print the elements of the bst
    cout<<"Printing the elements of the bst"<<endl;
    print(bst1);
    print(bst2);
    print(v);



    return 0;
}