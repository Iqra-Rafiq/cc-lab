#include <iostream>
#include <set>
#include <string>

// Function to display the contents of the set
void displayEmails(const std::set<std::string>& emailSet) {
    if (emailSet.empty()) {
        std::cout << "The email list is empty.\n";
    } else {
        std::cout << "Current unique email addresses:\n";
        for (const std::string& email : emailSet) {
            std::cout << email << std::endl;
        }
    }
}

// Function to insert a new email into the set
void insertEmail(std::set<std::string>& emailSet, const std::string& email) {
    auto result = emailSet.insert(email);
    if (result.second) {
        std::cout << "Email '" << email << "' was added successfully.\n";
    } else {
        std::cout << "Email '" << email << "' already exists in the set.\n";
    }
}

// Function to delete an email from the set
void deleteEmail(std::set<std::string>& emailSet, const std::string& email) {
    size_t removed = emailSet.erase(email);
    if (removed > 0) {
        std::cout << "Email '" << email << "' was removed successfully.\n";
    } else {
        std::cout << "Email '" << email << "' was not found in the set.\n";
    }
}

// Function to search for an email in the set
void searchEmail(const std::set<std::string>& emailSet, const std::string& email) {
    auto it = emailSet.find(email);
    if (it != emailSet.end()) {
        std::cout << "Email '" << email << "' exists in the set.\n";
    } else {
        std::cout << "Email '" << email << "' does not exist in the set.\n";
    }
}

int main() {
    std::set<std::string> emailSet;

    // Insert some email addresses
    insertEmail(emailSet, "alice@example.com");
    insertEmail(emailSet, "bob@example.com");
    insertEmail(emailSet, "alice@example.com");  // Duplicate, will not be added
    insertEmail(emailSet, "charlie@example.com");

    // Display the current emails
    displayEmails(emailSet);

    // Search for an email
    searchEmail(emailSet, "bob@example.com");
    searchEmail(emailSet, "david@example.com");  // Not in the set

    // Delete an email
    deleteEmail(emailSet, "alice@example.com");

    // Display the current emails after deletion
    displayEmails(emailSet);

    // Try to delete a non-existent email
    deleteEmail(emailSet, "david@example.com");

    return 0;
}
