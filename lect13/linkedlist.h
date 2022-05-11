//linkedlist.h
#include<iostream>
#include <vector>
using namespace std;
//Header guard
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <class T>
class LinkedList{
    public: 
        //Initialization list
        LinkedList():head(nullptr), tail(nullptr){
        }
        ~LinkedList(){
            // correctly free heap memory associated with the object 
            clear();
        }
        void prepend(T value);
        void append(T value);
        T getMax() const;
        T getMin() const;
        void clear();
        void print() const;
        bool search(T value) const;

    private:
        struct Node{
            T data;
            Node* next; // self-referencing type
        };
        Node* head;
        Node* tail; 
        void printList(Node* h) const;
        void clearList(Node* h);
        Node* search(Node* h, T value);
};
#include "linkedlist.cpp"

#endif
