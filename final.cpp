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

    void initializeQueue() {
        for (int i = 0; i < 3; i++) { // Adds 3 customers to the queue
            string name = names[generateRandomInt(0,names.size())];
            string drink = drinks[generateRandomInt(0,names.size())];
            
            queue.enqueue(name, drink); // Adding the customer to the queue
        }   
        queue.print();
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