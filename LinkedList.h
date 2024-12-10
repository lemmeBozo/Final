#ifndef LINKEDLIST_H
#define LINKEDLIST_H


template <typename T, typename D>
class LinkedList {
    // private:
    struct Node {
        T first;
        D second;
        Node* next;
        Node(T data, D dataTwo) {
            this->first = data;
            this->second = dataTwo;
            next = nullptr;
        }
    }

    Node* head;
    int CurrentSize;

    public:

    // Constructor and Destructor
    LinkedList(); 
    ~LinkedList() {clear();}

    // Setters
    void pushFront(T&, D&);


};


#endif


/*
TODO
*/