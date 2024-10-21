#include <iostream>
#include <queue>
#include <string>

// Function to process the customer at the front of the queue
void processCustomer(std::queue<std::string>& ticketQueue) {
    if (!ticketQueue.empty()) {
        std::cout << "Processing ticket for: " << ticketQueue.front() << std::endl;
        ticketQueue.pop();  // Remove the customer from the front after processing
    } else {
        std::cout << "No customers in the queue.\n";
    }
}

// Function to add a regular customer to the queue
void addRegularCustomer(std::queue<std::string>& ticketQueue, const std::string& customerName) {
    ticketQueue.push(customerName);
    std::cout << "Added regular customer: " << customerName << " to the queue.\n";
}

// Function to add a VIP customer (serve them next by placing them at the front)
void addVIPCustomer(std::queue<std::string>& ticketQueue, const std::string& customerName) {
    std::queue<std::string> tempQueue;
    tempQueue.push(customerName);  // Place VIP customer at the front of the new queue

    // Add all remaining customers from the old queue to the new one
    while (!ticketQueue.empty()) {
        tempQueue.push(ticketQueue.front());
        ticketQueue.pop();
    }

    // Replace the old queue with the new queue
    ticketQueue = tempQueue;
    std::cout << "Added VIP customer: " << customerName << " to the front of the queue.\n";
}

// Function to display the current queue
void displayQueue(const std::queue<std::string>& ticketQueue) {
    std::queue<std::string> tempQueue = ticketQueue;

    if (tempQueue.empty()) {
        std::cout << "The queue is currently empty.\n";
    } else {
        std::cout << "Current queue: ";
        while (!tempQueue.empty()) {
            std::cout << tempQueue.front() << " ";
            tempQueue.pop();
        }
        std::cout << std::endl;
    }
}

int main() {
    std::queue<std::string> ticketQueue;  // Queue to store the customers

    // Add some regular customers
    addRegularCustomer(ticketQueue, "Alice");
    addRegularCustomer(ticketQueue, "Bob");
    addRegularCustomer(ticketQueue, "Charlie");

    // Display the queue
    displayQueue(ticketQueue);

    // Add a VIP customer (should be served next)
    addVIPCustomer(ticketQueue, "VIP-David");

    // Display the queue
    displayQueue(ticketQueue);

    // Process customers in the queue
    processCustomer(ticketQueue);  // VIP-David should be served first
    processCustomer(ticketQueue);  // Alice should be served next

    // Add another regular customer
    addRegularCustomer(ticketQueue, "Eve");

    // Display the queue
    displayQueue(ticketQueue);

    // Process remaining customers
    processCustomer(ticketQueue);  // Bob
    processCustomer(ticketQueue);  // Charlie
    processCustomer(ticketQueue);  // Eve
    processCustomer(ticketQueue);  // No customers left

    return 0;
}
