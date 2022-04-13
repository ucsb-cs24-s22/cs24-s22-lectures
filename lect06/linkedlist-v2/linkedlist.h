//linkedlist.h
#include<iostream>
#include <vector>
using namespace std;
class LinkedList{
    public: 
        //Initialization list
        LinkedList():head(nullptr), tail(nullptr){
        }
        void prepend(string value);
        void append(string value);
        string getMax() const;
        string getMin() const;
        void clear();
        void print() const;
        bool search(string value) const;

    private:
        struct Node{
            string data;
            Node* next; // self-referencing type
        };
        Node* head;
        Node* tail; 
        void printList(Node* h) const;
        void clearList(Node* h);
};