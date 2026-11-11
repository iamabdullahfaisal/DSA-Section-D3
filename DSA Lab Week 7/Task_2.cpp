#include <iostream>
using namespace std;

// Each node contains data and the address of the next node.
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head; // First node of the list.

public:
    LinkedList() {
        head = nullptr; // An empty list has head = nullptr.
    }

    // Add a new node before the current first node.
    void insertBeginning(int value) {
        Node* newNode = new Node(value);

        newNode->next = head; // New node points to the old first node.
        head = newNode;       // Head now points to the new node.
    }

    // Add a new node at the end of the list.
    void insertEnd(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode; // First node in an empty list.
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next; // Keep moving until the last node.
        }

        temp->next = newNode; // Attach the new node at the end.
    }

    // Find and delete the first node that contains the given value.
    void deleteByValue(int value) {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        // Special case: the node to delete is the first node.
        if (head->data == value) {
            Node* temp = head;
            head = head->next; // Move head to the second node.
            delete temp;       // Free the old first node.
            cout << value << " deleted." << endl;
            return;
        }

        // Find the node just BEFORE the node to delete.
        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != value) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << value << " not found." << endl;
        } else {
            Node* nodeToDelete = temp->next;
            temp->next = nodeToDelete->next; // Skip the node being deleted.
            delete nodeToDelete;             // Free its memory.
            cout << value << " deleted." << endl;
        }
    }

    // Print all values from first node to last node.
    void display() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList list;

    list.insertBeginning(20);
    list.insertBeginning(10);
    list.insertEnd(30);

    cout << "List: ";
    list.display();

    list.deleteByValue(20);

    cout << "After deletion: ";
    list.display();

    return 0;
}
