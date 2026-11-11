#include <iostream>
#include <string>
using namespace std;

// Each node stores one patient's name and the next patient's address.
class Node {
public:
    string patientName;
    Node* next;

    Node(string name) {
        patientName = name;
        next = nullptr;
    }
};

class PatientQueue {
private:
    Node* head; // Points to the first patient in the waiting list.

public:
    PatientQueue() {
        head = nullptr; // Initially, no patients are waiting.
    }

    // Add a patient at the END of the waiting list.
    void addPatient(string name) {
        Node* newNode = new Node(name);

        if (head == nullptr) {
            head = newNode; // The new patient is the first patient.
        } else {
            Node* temp = head;

            while (temp->next != nullptr) {
                temp = temp->next; // Find the last patient.
            }

            temp->next = newNode; // Add the new patient after the last one.
        }

        cout << name << " added to the waiting list." << endl;
    }

    // Remove a patient by name if they cancel their appointment.
    void cancelPatient(string name) {
        if (head == nullptr) {
            cout << "Waiting list is empty." << endl;
            return;
        }

        // Check whether the first patient is cancelling.
        if (head->patientName == name) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << name << " removed from the waiting list." << endl;
            return;
        }

        // Search for the patient, keeping temp at the previous node.
        Node* temp = head;
        while (temp->next != nullptr && temp->next->patientName != name) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << "Patient not found." << endl;
        } else {
            Node* nodeToDelete = temp->next;
            temp->next = nodeToDelete->next;
            delete nodeToDelete;
            cout << name << " removed from the waiting list." << endl;
        }
    }

    // Display patients in the order they joined the waiting list.
    void displayPatients() {
        if (head == nullptr) {
            cout << "No patients are waiting." << endl;
            return;
        }

        Node* temp = head;
        cout << "Patient waiting list: ";

        while (temp != nullptr) {
            cout << temp->patientName << " -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }

    // Count the number of patients currently waiting.
    void countPatients() {
        int count = 0;
        Node* temp = head;

        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        cout << "Total patients: " << count << endl;
    }
};

int main() {
    PatientQueue queue;

    // Add sample patients.
    queue.addPatient("Ali");
    queue.addPatient("Ahmed");
    queue.addPatient("Sara");

    queue.displayPatients();

    // Ahmed cancels the appointment.
    queue.cancelPatient("Ahmed");

    queue.displayPatients();
    queue.countPatients();

    return 0;
}
