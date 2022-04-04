//linkedlist.cpp
//Lecture 3
#include<iostream>
#include <vector>
using namespace std;

struct Node{
    string data;
    Node* next; // self-referencing type
};

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

void clearList(Node* h){
    if(!h) return;
    clearList(h->next);
    delete h; // delete nullptr; OKAY!
}

int main(int argc, char const *argv[])
{
    vector<string> TAs {"Tina", "Zack", "Ganesh", "Roman"};
    //Node n1 {"Apoorva", nullptr}; //n1 is on the stack
    //Node* p = new Node {"Apoorva", nullptr}; // *p on the heap

    //Create an empty linked list
    Node* head = nullptr; 
    head = insertToFrontOfList(head, TAs[0]);
    printList(head);
    head = insertToFrontOfList(head, TAs[1]);
    printList(head);
    head = insertToFrontOfList(head, TAs[2]);
    printList(head);
    clearList(head);
    head = nullptr;
    printList(head);


    return 0;
}
