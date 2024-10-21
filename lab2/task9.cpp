#include <iostream>
#include <unordered_map>
#include <map>
#include <sstream>
#include <chrono>  // For measuring time

// Function to count word frequency using unordered map
void countWordFrequencyUnordered(const std::string& text) {
    std::unordered_map<std::string, int> wordCount;
    std::istringstream stream(text);
    std::string word;

    // Insert words into the unordered map and count occurrences
    while (stream >> word) {
        wordCount[word]++;
    }

    // Display word frequencies
    std::cout << "Word frequencies using unordered map:\n";
    for (const auto& pair : wordCount) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
}

// Function to count word frequency using ordered map
void countWordFrequencyOrdered(const std::string& text) {
    std::map<std::string, int> wordCount;
    std::istringstream stream(text);
    std::string word;

    // Insert words into the ordered map and count occurrences
    while (stream >> word) {
        wordCount[word]++;
    }

    // Display word frequencies
    std::cout << "Word frequencies using ordered map:\n";
    for (const auto& pair : wordCount) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
}

int main() {
    std::string text = "this is a test this is only a test test the system with unordered and ordered maps";

    // Measure time for unordered map
    auto startUnordered = std::chrono::high_resolution_clock::now();
    countWordFrequencyUnordered(text);
    auto endUnordered = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsedUnordered = endUnordered - startUnordered;
    std::cout << "Time taken using unordered map: " << elapsedUnordered.count() << " seconds\n\n";

    // Measure time for ordered map
    auto startOrdered = std::chrono::high_resolution_clock::now();
    countWordFrequencyOrdered(text);
    auto endOrdered = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsedOrdered = endOrdered - startOrdered;
    std::cout << "Time taken using ordered map: " << elapsedOrdered.count() << " seconds\n";

    return 0;
}
