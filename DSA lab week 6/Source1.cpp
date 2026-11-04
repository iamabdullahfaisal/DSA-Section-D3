
#include <iostream>
#include <stack>
using namespace std;

class Queue {
private:
    stack<int> stack1;
    stack<int> stack2;

    // Transfer elements from stack1 to stack2
    void transfer() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
    }

public:
    // Insert element into queue
    void enqueue(int value) {
        stack1.push(value);
        cout << value << " inserted successfully!" << endl;
    }

    // Remove front element
    int dequeue() {
        transfer();

        if (stack2.empty()) {
            cout << "Queue is Empty!" << endl;
            return -1;
        }

        int value = stack2.top();
        stack2.pop();

        return value;
    }

    // Return front element
    int front() {
        transfer();

        if (stack2.empty()) {
            cout << "Queue is Empty!" << endl;
            return -1;
        }

        return stack2.top();
    }

    // Check if queue is empty
    bool isEmpty() {
        return stack1.empty() && stack2.empty();
    }

    // Display all queue elements
    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }

        stack<int> temp;

        // Display stack2 elements first
        stack<int> copy1 = stack2;

        cout << "Queue elements: ";

        while (!copy1.empty()) {
            cout << copy1.top() << " ";
            copy1.pop();
        }

        // Reverse stack1 to display in queue order
        stack<int> copy2 = stack1;

        while (!copy2.empty()) {
            temp.push(copy2.top());
            copy2.pop();
        }

        while (!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
        }

        cout << endl;
    }
};

int main() {
    Queue q;
    int choice, value;

    do {
        cout << "\n===== QUEUE USING STACKS =====" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Front Element" << endl;
        cout << "4. Display Queue" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            q.enqueue(value);
            break;

        case 2:
            if (!q.isEmpty())
                cout << "Removed element: " << q.dequeue() << endl;
            else
                cout << "Queue is Empty!" << endl;
            break;

        case 3:
            if (!q.isEmpty())
                cout << "Front element: " << q.front() << endl;
            else
                cout << "Queue is Empty!" << endl;
            break;

        case 4:
            q.display();
            break;

        case 5:
            cout << "Program terminated." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 5);

    return 0;
}
