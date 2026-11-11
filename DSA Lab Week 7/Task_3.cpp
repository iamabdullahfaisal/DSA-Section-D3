#include <iostream>
using namespace std;

// A node is one element of the linked list.
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
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Insert a value at a position. Positions start from 1.
    void insertAtPosition(int value, int position) {
        if (position < 1) {
            cout << "Invalid position." << endl;
            return;
        }

        Node* newNode = new Node(value);

        // Position 1 means insert before the current head.
        if (position == 1) {
            newNode->next = head;
            head = newNode;
            return;
        }

        // Stop at the node just before the required position.
        Node* temp = head;
        for (int i = 1; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        // If temp is nullptr, the requested position is too far.
        if (temp == nullptr) {
            cout << "Invalid position." << endl;
            delete newNode;
            return;
        }

        // Connect the new node between temp and temp->next.
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Delete the node at the given position. Positions start from 1.
    void deleteAtPosition(int position) {
        if (head == nullptr || position < 1) {
            cout << "Invalid position or empty list." << endl;
            return;
        }

        // Special case: delete the first node.
        if (position == 1) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        // Find the node before the one that must be deleted.
        Node* temp = head;
        for (int i = 1; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (temp == nullptr || temp->next == nullptr) {
            cout << "Invalid position." << endl;
            return;
        }

        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next; // Join the nodes around it.
        delete nodeToDelete;
    }

    // Search for a value and print its position.
    void search(int value) {
        Node* temp = head;
        int position = 1;

        while (temp != nullptr) {
            if (temp->data == value) {
                cout << value << " found at position " << position << "." << endl;
                return;
            }

            temp = temp->next;
            position++;
        }

        cout << value << " not found." << endl;
    }

    // Count nodes by visiting each node once.
    void countNodes() {
        int count = 0;
        Node* temp = head;

        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        cout << "Total nodes: " << count << endl;
    }

    // Display all nodes in order.
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
    int choice, value, position;

    // Repeat the menu until the user selects 0.
    do {
        cout << "\n1. Insert at position" << endl;
        cout << "2. Delete at position" << endl;
        cout << "3. Search" << endl;
        cout << "4. Count nodes" << endl;
        cout << "5. Display" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        // Run the operation selected by the user.
        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            cout << "Enter position: ";
            cin >> position;
            list.insertAtPosition(value, position);
            break;

        case 2:
            cout << "Enter position: ";
            cin >> position;
            list.deleteAtPosition(position);
            break;

        case 3:
            cout << "Enter value to search: ";
            cin >> value;
            list.search(value);
            break;

        case 4:
            list.countNodes();
            break;

        case 5:
            list.display();
            break;

        case 0:
            cout << "Program ended." << endl;
            break;

        default:
            cout << "Invalid choice." << endl;
        }

    } while (choice != 0);

    return 0;
}
