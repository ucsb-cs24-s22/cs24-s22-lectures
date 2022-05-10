//stl.cpp
//STL: standard template library

#include<set>
#include<vector>
#include <iostream>
using namespace std;

int main(){
    vector<int> v {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    set<int> s; // BALANCED BST
    set<string> bst {"Vaishali", "Diba", "Victor"};
    //set<Complex> cbst; We'll do this next time!
    for(auto item: v){
        s.insert(item);
    }
    // height of bst if set was a regular bst: 10 , height n
    // but actually set is a balanced bst and so height = O(log n) 
    // print the elements of the bst
    cout<<"Printing the elements of the bst"<<endl;
    for(auto item: bst){ //inorder traversal of the bst 
        cout<<item<<endl;
    }



    return 0;
}