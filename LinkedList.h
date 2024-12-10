#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// Queue

template <typename T, typename D>
class LinkedList {
    // private:
    struct Node {
        T first;
        D second;
        Node* next;
        Node(T dataOne, D dataTwo) {
            this->first = dataOne;
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

    // Container methods
    void enqueue(T&, D&); // Adds a element to the front of the queue
    void dequeue(); // Removes the frist element from the queue
    T peek(); // returns the value of the front element in the queue
    bool isEmpty() {return (head == nullptr);}
    int size() {return CurrentSize;}
    void clear();

};


#endif

// Default Constructor function
template <typename T, typename D>
LinkedList<T,D>::LinkedList() {
    this->head = nullptr;
    this->CurrentSize = 0;
}

template <typename T, typename D>
void LinkedList<T,D>::enqueue(T&, D&) {
    Node* node = new Node(dataOne, dataTwo);
    if(this->isEmpty()) { // If the queue is empty
        head = node; // the element added is now at the front (i.e. is the head)
    } else {
        Node* temp = head;
        while(temp->next != nullptr) { // traveres through queue until recahing the last element
            temp = temp->next; 
        }
        temp->next = node;
    }
}

