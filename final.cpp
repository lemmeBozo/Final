#include <iostream>
#include <list>
#include <vector>

#include <random>
#include <chrono>

#include <sstream>

#include "LinkedList.h" // Including custom data structure

using namespace std;

// COMSC-210 | Lab FINAL | Erick Pascual-Bautista

// Function prototypes
mt19937& getGenerator();
int generateRandomInt(int, int);

struct Booth {
    // public:
    virtual void initializeQueue() = 0; // Pure virtual function
    virtual string simulateRonud() = 0; // Pure virtual function
    // virtual ~Booth() {}
    
};

struct CoffeeBooth : public Booth {
    // private: (make private later)

    LinkedList<string, string> queue;
    vector<string> names = {
        "Alice", "Bob", "Charlie", "Diana", "Eve",
        "Frank", "Grace", "Hank", "Isabella", "Jack",
        "Karen", "Liam", "Mia", "Nathan", "Olivia",
        "Paul", "Quincy", "Rachel", "Sophia", "Tom"
    };
    vector<string> drinks = {
        "Coffee", "Tea", "Latte", "Mocha", "Espresso",
        "Cappuccino", "Americano", "Macchiato", "Flat White", "Affogato",
        "Hot Chocolate", "Chai Latte", "Green Tea", "Herbal Tea", "Iced Coffee",
        "Iced Latte", "Smoothie", "Matcha", "Turmeric Latte", "Black Tea"
    };

    // public:    
    void addCustomer() {
        string name = names[generateRandomInt(0,names.size() - 1)];
        string drink = drinks[generateRandomInt(0,names.size() - 1)];
        queue.enqueue(name, drink); // Adding the customer to the queue
    }

    void initializeQueue() override{
        for (int i = 0; i < 3; i++) { // Adds 3 customers to the queue
            this->addCustomer();
        }   
    }
    string simulateRonud() override {
        stringstream RoundResult;
        RoundResult << "Coffee Booth: \n";

        if (!queue.isEmpty()) {
            RoundResult << "Serving: [Name: " << queue.peekFirst()
                   << ", Drink: " << queue.peekSecond() << "]\n";
        }
    }
};



// struct CofeeBoothSimulator {

//     void run() {
//         int rounds = 10;
//         for (int i = 0; i < rounds; i++) {
//             cout << "\n===== Round " << i + 1 << " =====\n";

//             // Server the customer at the head of the queue
//             if (!queue.isEmpty()) {
//                 cout << "Serving customer: [Name: " << queue.peekFirst() 
//                     << ", Drink: " << queue.peekSecond() << "]\n";
//                 queue.dequeue(); // remove the person from the queue
//             } else {
//                 cout << "Queue is empty. No one to serve.\n";
//             }

//             // 50% chance of a new customer joining the queue
//             if (generateRandomInt(0,1) == 1) {
//                 cout << "A new customer has joined the queue.\n";
//                 this->addCustomer();
//             } else {cout << "No new customers joined this round.\n";}

//             // Printing the queue after the end of the round
//             cout << "Queue at the end of round " << i + 1 << ":\n";
//             queue.print();
//         }
//         cout << "\n--- Simulation Complete ---\n";        
//     }

// };

int main() {
    
    // CofeeBoothSimulator sim;
    // sim.initializeQueue();
    // sim.run();


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