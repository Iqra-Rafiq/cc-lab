#include <iostream>
#include <string>

// Node structure for the doubly linked list
struct Node {
    std::string webpage;
    Node* prev;
    Node* next;

    Node(std::string url) : webpage(url), prev(nullptr), next(nullptr) {}
};

// Doubly Linked List to manage webpages
class BrowserHistory {
private:
    Node* current;

public:
    // Constructor
    BrowserHistory() : current(nullptr) {}

    // Add a new webpage to the list
    void visit(const std::string& url) {
        Node* newNode = new Node(url);
        if (current != nullptr) {
            current->next = newNode;  // Link current to the new node
            newNode->prev = current;  // Link the new node back to current
        }
        current = newNode;  // Move to the new node (new page)
        std::cout << "Visited: " << current->webpage << std::endl;
    }

    // Move backward in the history
    void back() {
        if (current && current->prev) {
            current = current->prev;
            std::cout << "Moved back to: " << current->webpage << std::endl;
        } else {
            std::cout << "No previous page!" << std::endl;
        }
    }

    // Move forward in the history
    void forward() {
        if (current && current->next) {
            current = current->next;
            std::cout << "Moved forward to: " << current->webpage << std::endl;
        } else {
            std::cout << "No next page!" << std::endl;
        }
    }

    // Delete the current webpage (removes from history)
    void deleteCurrentPage() {
        if (!current) return;

        Node* temp = current;

        if (current->prev) {
            current->prev->next = current->next;  // Bypass the current node
        }
        if (current->next) {
            current->next->prev = current->prev;
            current = current->next;  // Move forward after deletion
        } else {
            current = current->prev;  // Move backward if there is no forward page
        }

        std::cout << "Deleted page: " << temp->webpage << std::endl;
        delete temp;
    }

    // Display current page
    void displayCurrentPage() const {
        if (current) {
            std::cout << "Currently on: " << current->webpage << std::endl;
        } else {
            std::cout << "No current page!" << std::endl;
        }
    }
};

int main() {
    BrowserHistory browser;

    browser.visit("google.com");
    browser.visit("stackoverflow.com");
    browser.visit("github.com");

    browser.back();
    browser.displayCurrentPage();

    browser.forward();
    browser.displayCurrentPage();

    browser.deleteCurrentPage();
    browser.displayCurrentPage();

    browser.back();
    browser.displayCurrentPage();

    return 0;
}
