#include <iostream>
#include <list>
#include <vector>

#include <random>
#include <chrono>

#include "LinkedList.h" // Including custom data structure

using namespace std;

// COMSC-210 | Lab FINAL | Erick Pascual-Bautista

// Function prototypes
mt19937& getGenerator();
int generateRandomInt(int, int);

struct CofeeBoothSimulator {
    LinkedList<string, string> queue;

    vector<string> names = {"Alice", "Bob", "Charlie", "Diana", "Eve"};
    vector<string> drinks = {"Coffee", "Tea", "Latte", "Mocha", "Espresso"};

    void addCustomer() {
        string name = names[generateRandomInt(0,names.size() - 1)];
        string drink = drinks[generateRandomInt(0,names.size() - 1)];
        queue.enqueue(name, drink); // Adding the customer to the queue
    }

    void initializeQueue() {
        for (int i = 0; i < 3; i++) { // Adds 3 customers to the queue
            this->addCustomer();
        }   
        cout << "Beggining Simulation, Printing initial line" << endl;
        queue.print();
    }

    void run() {
        int rounds = 10;
        for (int i = 0; i < rounds; i++) {
            cout << "\t Ronud "<< i + 1 << ": " << endl;

            // Server the customer at the head of the queue
            if (!queue.isEmpty()) {
                cout << "Serving [" << queue.peekFirst() << "] with [" << queue.peekSecond() << "]" << endl;
                queue.dequeue(); // remove the person from the queue
            } else {
                cout << "Queue is empty. No one to server" << endl;
            }

            // 50% chance of a new customer joining the queue
            if (generateRandomInt(0,1) == 1) {
                this->addCustomer();
            }
        }
    }

};


int main() {
    
    CofeeBoothSimulator sim;
    sim.initializeQueue();


    return 0;
}


// Seeding function
mt19937& getGenerator() {
    static mt19937 generator(static_cast<unsigned>(
        chrono::high_resolution_clock::now().time_since_epoch().count())); // Seed with high-resolution clock
    return generator;
}

// Function to generate a random integer within a given range
int generateRandomInt(int min, int max) {
    uniform_int_distribution<int> distribution(min, max);
    return distribution(getGenerator());
}