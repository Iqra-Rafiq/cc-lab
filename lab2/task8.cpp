#include <iostream>
#include <map>
#include <string>

// Struct to store student details
struct Student {
    std::string name;
    float grade;
};

// Function to add a new student to the map
void addStudent(std::map<int, Student>& studentRecords, int studentID, const std::string& name, float grade) {
    studentRecords[studentID] = {name, grade};  // Insert student details using student ID as the key
    std::cout << "Student added: ID=" << studentID << ", Name=" << name << ", Grade=" << grade << std::endl;
}

// Function to delete a student record by ID
void deleteStudent(std::map<int, Student>& studentRecords, int studentID) {
    if (studentRecords.erase(studentID)) {
        std::cout << "Student with ID " << studentID << " deleted.\n";
    } else {
        std::cout << "Student with ID " << studentID << " not found.\n";
    }
}

// Function to retrieve and display a student's details by ID
void getStudent(const std::map<int, Student>& studentRecords, int studentID) {
    auto it = studentRecords.find(studentID);
    if (it != studentRecords.end()) {
        std::cout << "Student found: ID=" << studentID << ", Name=" << it->second.name << ", Grade=" << it->second.grade << std::endl;
    } else {
        std::cout << "Student with ID " << studentID << " not found.\n";
    }
}

// Function to display all student records
void displayAllStudents(const std::map<int, Student>& studentRecords) {
    if (studentRecords.empty()) {
        std::cout << "No student records found.\n";
    } else {
        std::cout << "All Student Records:\n";
        for (const auto& record : studentRecords) {
            std::cout << "ID=" << record.first << ", Name=" << record.second.name << ", Grade=" << record.second.grade << std::endl;
        }
    }
}

int main() {
    std::map<int, Student> studentRecords;  // Map to store student records with student ID as key

    // Add some students to the system
    addStudent(studentRecords, 101, "Alice", 85.5);
    addStudent(studentRecords, 102, "Bob", 92.0);
    addStudent(studentRecords, 103, "Charlie", 78.3);

    // Display all student records
    displayAllStudents(studentRecords);

    // Retrieve a specific student by ID
    getStudent(studentRecords, 102);  // Bob's record
    getStudent(studentRecords, 105);  // Non-existent record

    // Delete a student by ID
    deleteStudent(studentRecords, 103);  // Delete Charlie's record
    deleteStudent(studentRecords, 105);  // Try deleting non-existent record

    // Display all student records after deletion
    displayAllStudents(studentRecords);

    return 0;
}
