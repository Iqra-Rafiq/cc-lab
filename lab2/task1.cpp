#include <iostream>
#include <vector>

int main() {
    // Declare a vector to store integers (student grades)
    std::vector<int> grades;

    // Append (insert) elements into the vector
    grades.push_back(10);
    grades.push_back(20);
    grades.push_back(30);
    grades.push_back(40);

    // Print the vector elements and size/capacity
    std::cout << "Vector after insertions: ";
    for (int grade : grades) {
        std::cout << grade << " ";
    }
    std::cout << std::endl;
    std::cout << "Size: " << grades.size() << ", Capacity: " << grades.capacity() << std::endl;

    // Add more elements to trigger automatic resizing
    grades.push_back(50);
    grades.push_back(60);

    std::cout << "Vector after more insertions: ";
    for (int grade : grades) {
        std::cout << grade << " ";
    }
    std::cout << std::endl;
    std::cout << "Size: " << grades.size() << ", Capacity: " << grades.capacity() << std::endl;

    // Access a specific element by index
    std::cout << "Element at index 2: " << grades[2] << std::endl;

    // Remove the last element (pop)
    grades.pop_back();
    std::cout << "Vector after popping last element: ";
    for (int grade : grades) {
        std::cout << grade << " ";
    }
    std::cout << std::endl;
    std::cout << "Size: " << grades.size() << ", Capacity: " << grades.capacity() << std::endl;




    return 0;
}
