#include <iostream>
#include <list>
#include <vector>
#include <deque>
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
    virtual string simulateRonud() = 0; // Pure virtual function (too late now mispelled it)
    // virtual ~Booth() {}
    
};

struct CoffeeBooth : public Booth {
    // public: 
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

    void initializeQueue() override{
        for (int i = 0; i < 3; i++) { // Adds 3 customers to the queue
            this->addCustomer();
        }   
    }
    
    string simulateRonud() override {
        stringstream RoundResult;
        RoundResult << "Coffee Booth: \n";
        RoundResult << queue.print() << "\n";
        if (!queue.isEmpty()) {
            RoundResult << "Serving: [Name: " << queue.peekFirst()
                   << ", Drink: " << queue.peekSecond() << "]\n";
            queue.dequeue();
        } else {RoundResult << "Queue is empty. No one to serve.\n";}

        if (generateRandomInt(0,1) == 1) {
            RoundResult << "A new customer has joined the queue.\n";
            this->addCustomer();
        } else {RoundResult << "No new customers joined this round.\n";}
        return RoundResult.str(); // Return the stringstream as a string
    }

    private:
    void addCustomer() {
        string name = names[generateRandomInt(0,names.size() - 1)];
        string drink = drinks[generateRandomInt(0,names.size() - 1)];
        queue.enqueue(name, drink); // Adding the customer to the queue
    } 
};

struct MuffinBooth : public Booth {
    // public:
    deque<pair<string,string>> queue; 
    vector<string> names = {
    "Alice", "Bob", "Charlie", "Diana", "Eve",
    "Frank", "Grace", "Hank", "Isabella", "Jack",
    "Karen", "Liam", "Mia", "Nathan", "Olivia",
    "Paul", "Quincy", "Rachel", "Sophia", "Tom"
    };

    vector<std::string> muffins = {
        "Blueberry", "Chocolate Chip", "Banana Nut", "Pumpkin", "Corn"
    };

    void initializeQueue() override {
        for (int i = 0; i < 3; i++) {
            addCustomer();
        }
    }

    string simulateRonud() override {
        stringstream RoundResult;
        RoundResult << "\nMuffin Booth: \n";
        RoundResult << getQueueState() << "\n";
        if (!queue.empty()) {
            auto served = queue.front();

            RoundResult << "Serving: [Name: " << served.first
                   << ", Drink: " << served.second << "]\n";
            queue.pop_front();
        } else {RoundResult << "Queue is empty. No one to serve.\n";}

        if (generateRandomInt(0,1) == 1) {
            RoundResult << "A new customer has joined the queue.\n";
            this->addCustomer();
        } else {RoundResult << "No new customers joined this round.\n";}
        return RoundResult.str(); // Return the stringstream as a string
    }

    private:
    void addCustomer() {
        string name = names[generateRandomInt(0,names.size() - 1)];
        string muffin = muffins[generateRandomInt(0,muffins.size() - 1)];
        queue.push_back({name, muffin});
    }

    string getQueueState() {
        if (queue.empty()) {return "[Empty]";}
        stringstream state;
        for (auto& customer : queue) {
            state << "[" << customer.first << "] = [" << customer.second << "]\n";
        }
        return state.str();
    }

};

struct FriendshipBooth : public Booth {
    // public:
    vector<pair<string, string>> queue;
    vector<string> names = {
        "Alice", "Bob", "Charlie", "Diana", "Eve",
        "Frank", "Grace", "Hank", "Isabella", "Jack",
        "Karen", "Liam", "Mia", "Nathan", "Olivia",
        "Paul", "Quincy", "Rachel", "Sophia", "Tom"
    };
    vector<std::string> bracelets = {
        "Friendship", "Beaded", "Charm", "Bangle", "Cuff"
    };

    private:
    void addCustomer() {
        
    }
}

class SimulationManager {
    // private:
    vector<Booth*> booths;

    public:
    // Create destructor here

    void addBooth(Booth* booth) {
        booths.push_back(booth);
    }

    void initializeAll() { // Initializes all booths
        for (Booth* booth : booths) {
            booth->initializeQueue();
        }
    }

    void RunSimulation() {
        int rounds = 10;
        for (int i = 0; i < rounds; i++) {
            cout << "\n===== Round " << i + 1 << " =====\n";
            for (Booth* booth : booths) {
                cout << booth->simulateRonud();
            }
        }
    }
};


int main() {
    
    SimulationManager manager;
    manager.addBooth(new CoffeeBooth);
    manager.addBooth(new MuffinBooth);
    manager.initializeAll();
    manager.RunSimulation();


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