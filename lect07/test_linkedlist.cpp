// test_linkedlist.cpp
#include "linkedlist.h"
#include "util.h"
using namespace std;

void test_prepend(){
    vector<string> TAs {"Tina", "Zack", "Ganesh", "Roman"};
    LinkedList list; //empty linkedlist 
    list.prepend(TAs[0]);
    list.print();
    list.prepend(TAs[1]);
    list.print();
    list.prepend(TAs[2]);;
    list.print();
    list.prepend(TAs[3]);
    list.print();
}

void test_copyconstructor(){
    vector<string> TAs {"Tina", "Zack", "Ganesh", "Roman"};
    LinkedList l1; 
    for(string elem: TAs){
        l1.prepend(elem);
    }
    l1.print();

    LinkedList l2 {l1}; //C++ default is used
    // LinkedList l2 = l1;
    // LinkedList l2(l1);
    l2.print();

}

void example_segfault(){
    //Cases where you will definitely or likely get a seg fault
    int* p = nullptr;
    cout<<p<<endl; // No seg fault
    //(1) De-reference a null pointer
    //cout<<*p<<endl;  // Definite seg fault
    //(2) Out of bound array access - may or may not lead to a segfault 
    //(3) Double deletion (double free)
    p = new int{10};
    delete p; // p = nullptr;
    delete p; // double delete leads to segfault but deleting a null ptr is okay

}

int main(int argc, char const *argv[])
{
    test_prepend();
    //example_segfault();
    //test_copyconstructor();
    return 0;
}
