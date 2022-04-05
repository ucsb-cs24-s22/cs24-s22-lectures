//linkedlist.cpp
//Lecture 3
#include<iostream>
#include <vector>
using namespace std;


struct Node{
    string data;
    Node* next; // self-referencing type
};

struct LinkedList{
    Node* head;
    Node* tail;
    
};
/* How do we represent the linked list as a parameter to the function
A. LinkedList* mylist
B. LinkedList& mylist
C. const LinkedList& mylist
D. LinkedList mylist
*/
Node* insertToFrontOfList(Node* h , string value);

void insertToFrontOfList(LinkedList& mylist, string value){
    mylist.head = insertToFrontOfList(mylist.head, value);
    if(!mylist.tail){     
        //empty linked list
        mylist.tail = mylist.head;

    } 
}

// Precondition: @param1 : LinkeList, @param2: string value
// Postcondition: Insert value to the front of the list and return 
// the resulting linked list
//
Node* insertToFrontOfList(Node* h , string value){
    //Create a new node
    // Node* p = new Node {value, h};
    // Update the head pointer
    // h = p;
    // p->next = h;
    // Return the modified linked list
    // return p;
    return new Node {value, h};

}

void printList(Node* h){
    Node* t = h; // t  is a traversal 
    while(t){ // same as while (t!=nullptr)
        cout<<t->data<<" ";
        t = t->next;
    }
    cout<<endl;
}
void printList(const LinkedList& mylist){
    printList(mylist.head);
}

void clearList(Node* h){
    if(!h) return;
    clearList(h->next);
    delete h; // delete nullptr; OKAY!
}

void clearList(LinkedList& mylist){
    clearList(mylist.head);
    mylist.head = mylist.tail = nullptr;
}

int main(int argc, char const *argv[])
{
    vector<string> TAs {"Tina", "Zack", "Ganesh", "Roman"};
    //Node n1 {"Apoorva", nullptr}; //n1 is on the stack
    //Node* p = new Node {"Apoorva", nullptr}; // *p on the heap

    //Create an empty linked list
    LinkedList list {nullptr, nullptr}; //empty linkedlist 
    insertToFrontOfList(list, TAs[0]);
    printList(list);
    insertToFrontOfList(list, TAs[1]);
    printList(list);
    insertToFrontOfList(list, TAs[2]);
    printList(list);
    insertToFrontOfList(list, TAs[3]);
    printList(list);
    clearList(list);
    printList(list);


    return 0;
}
