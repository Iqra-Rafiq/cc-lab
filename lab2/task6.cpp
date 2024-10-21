#include <iostream>
#include <queue>
#include <vector>
#include <string>

struct Patient {
    std::string name;
    int severity;  // Higher value means more severe condition

    // Constructor
    Patient(std::string n, int s) : name(n), severity(s) {}
};

// Comparator for priority queue to ensure highest severity gets priority
struct CompareSeverity {
    bool operator()(const Patient& p1, const Patient& p2) {
        return p1.severity < p2.severity;  // Higher severity gets higher priority
    }
};

int main() {
    // Priority queue with custom comparator
    std::priority_queue<Patient, std::vector<Patient>, CompareSeverity> hospitalQueue;

    // Add patients to the queue
    hospitalQueue.push(Patient("John", 5));   // John has severity 5
    hospitalQueue.push(Patient("Sarah", 8));  // Sarah has severity 8 (higher priority)
    hospitalQueue.push(Patient("Alex", 3));   // Alex has severity 3
    hospitalQueue.push(Patient("Emma", 10));  // Emma has severity 10 (highest priority)
    
    // Process patients based on severity
    while (!hospitalQueue.empty()) {
        Patient currentPatient = hospitalQueue.top();
        std::cout << "Attending patient: " << currentPatient.name << " with severity " 
                  << currentPatient.severity << std::endl;
        hospitalQueue.pop();
    }

    return 0;
}
