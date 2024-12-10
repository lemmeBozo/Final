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
        };
    };

    Node* head;
    int CurrentSize;

    public:

    // Constructor and Destructor
    LinkedList(); 
    ~LinkedList() {clear();}

    // Container methods
    void enqueue(T&, D&); // Adds a element to the front of the queue
    void dequeue(); // Removes the frist element from the queue

    T peekFirst(); // returns the value of the front element in the queue
    D peekSecond(); // retruns the value of the front element in the queue

    bool isEmpty() {return (head == nullptr);}
    int size() {return CurrentSize;}
    void clear();
    void print(ostream& os) con;

};


#endif

// Default Constructor function
template <typename T, typename D>
LinkedList<T,D>::LinkedList() {
    this->head = nullptr;
    this->CurrentSize = 0;
}

template <typename T, typename D>
void LinkedList<T,D>::enqueue(T& dataOne, D& dataTwo) {
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
    CurrentSize++;
}

template <typename T, typename D>
void LinkedList<T,D>::dequeue() {
    if (!this->isEmpty()) { // If the list isn't empty, removes the first element
        Node* temp = head;  
        head = head->next;
        delete temp;
        CurrentSize--;
    }
}

template<typename T, typename D> 
T LinkedList<T,D>::peekFirst() {
    return head->first;
}

template<typename T, typename D> 
D LinkedList<T,D>::peekSecond() {
    return head->second;
}

template <typename T, typename D>
void LinkedList<T,D>::clear() {
    while(!this->isEmpty()) { // while the list isn't empty pop all the elements
        dequeue();
    }
}

// Printing method
template <typename T, typename D>
void LinkedList<T, D>::print() {
    Node* temp = head; 
    while (temp != nullptr) {
        std::cout << "[" << temp->first << "] = [" << temp->second << "]\n"; 
        temp = temp->next; 
    }
}



