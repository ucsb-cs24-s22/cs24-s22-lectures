//linkedlist.cpp

template <class T>
void LinkedList<T>::prepend(T value){
    head = new Node {value, head};
    if(!tail){     
        //empty linked list
        tail = head;
    } 
    return;
}

template <class T>
void LinkedList<T>::append(T value){
    return;
}

template <class T>
T LinkedList<T>::getMax() const{
    return "42";
}

template <class T>
T LinkedList<T>::getMin() const{
    return "42";
}

template <class T>
void LinkedList<T>::clear(){
    clearList(head);
    head = tail = nullptr;
    return;
}

template <class T>
bool LinkedList<T>::search(T value) const{
    Node* h = search(head, value);
    if(!h) return true;
    return false;
}

template <class T>
typename LinkedList<T>::Node* LinkedList<T>::search(Node* h, T value){
    return nullptr;
}

template <class T>
void LinkedList<T>::print() const{
    printList(head);
}

    
// Precondition: @param1 : LinkeList, @param2: T value
// Postcondition: Insert value to the front of the list and return 
// the resulting linked list

template <class T>
void LinkedList<T>::printList(Node* h) const{
    Node* t = h; // t  is a traversal 
    while(t){ // same as while (t!=nullptr)
        cout<<t->data<<" ";
        t = t->next;
    }
    cout<<endl;
}

template <class T>
void LinkedList<T>::clearList(Node* h){
    if(!h) return;
    clearList(h->next);
    delete h; // delete nullptr; OKAY!
}






