
#include <iostream>
#include <queue>
using namespace std;

class TicketSystem {
private:
    queue<int> tickets;

public:
    // Add new ticket
    void enqueue(int ticket_id) {
        if (ticket_id < 1000 || ticket_id > 9999) {
            cout << "Invalid Ticket ID! Enter a 4-digit ID." << endl;
            return;
        }

        // Check duplicate ticket ID
        queue<int> temp = tickets;

        while (!temp.empty()) {
            if (temp.front() == ticket_id) {
                cout << "Ticket ID already exists!" << endl;
                return;
            }
            temp.pop();
        }

        tickets.push(ticket_id);

        cout << "Ticket " << ticket_id
            << " added successfully!" << endl;
    }

    // Resolve ticket
    void dequeue() {
        if (tickets.empty()) {
            cout << "No pending tickets!" << endl;
            return;
        }

        cout << "Ticket "
            << tickets.front()
            << " has been resolved!" << endl;

        tickets.pop();
    }

    // Show next ticket
    void front() {
        if (tickets.empty()) {
            cout << "No pending tickets!" << endl;
            return;
        }

        cout << "Next ticket to resolve: "
            << tickets.front() << endl;
    }

    // Display all pending tickets
    void display() {
        if (tickets.empty()) {
            cout << "No pending tickets!" << endl;
            return;
        }

        queue<int> temp = tickets;

        cout << "\nPending Tickets:" << endl;

        while (!temp.empty()) {
            cout << "Ticket ID: "
                << temp.front() << endl;

            temp.pop();
        }
    }
};

int main() {
    TicketSystem system;

    int choice, ticket_id;

    do {
        cout << "\n===== CUSTOMER SUPPORT SYSTEM =====" << endl;
        cout << "1. Add New Ticket" << endl;
        cout << "2. Resolve Ticket" << endl;
        cout << "3. Next Ticket" << endl;
        cout << "4. Display Pending Tickets" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter 4-digit Ticket ID: ";
            cin >> ticket_id;

            system.enqueue(ticket_id);
            break;

        case 2:
            system.dequeue();
            break;

        case 3:
            system.front();
            break;

        case 4:
            system.display();
            break;

        case 5:
            cout << "Exiting Customer Support System."
                << endl;
            break;

        default:
            cout << "Invalid choice! Try again." << endl;
        }

    } while (choice != 5);

    return 0;
}
