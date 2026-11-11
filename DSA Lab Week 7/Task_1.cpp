#include <iostream>
using namespace std;

// A node stores one value and the address of the next node.
class Node {
public:
    int data;
    Node* next;

    // Set the value and make next point to nothing initially.
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head; // Points to the first node of the list.

public:
    // At the start, the list has no nodes.
    LinkedList() {
        head = nullptr;
    }

    // Create a new node and add it at the END of the list.
    void CreateNode(int value) {
        Node* newNode = new Node(value);

        // If the list is empty, the new node becomes the first node.
        if (head == nullptr) {
            head = newNode;
            return;
        }

        // Move temp from the first node to the last node.
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        // Connect the last node to the new node.
        temp->next = newNode;
    }

    // Visit and print every node, starting from head.
    void Display() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next; // Move to the next node.
        }
        cout << "NULL" << endl; // NULL means there is no next node.
    }
};

int main() {
    LinkedList list;

    // Add three values to the list.
    list.CreateNode(10);
    list.CreateNode(20);
    list.CreateNode(30);

    cout << "Singly Linked List: ";
    list.Display();

    return 0;
}
