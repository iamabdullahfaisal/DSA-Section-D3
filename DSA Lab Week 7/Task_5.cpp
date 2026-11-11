#include <iostream>
#include <string>
using namespace std;

// Each node stores a student's name, priority, and next node address.
class StudentNode {
public:
    string studentName;
    int priority;
    StudentNode* next;

    StudentNode(string name, int p) {
        studentName = name;
        priority = p;
        next = nullptr;
    }
};

class BookQueue {
private:
    string bookName;
    StudentNode* head; // First student in this book's reservation list.

public:
    BookQueue(string name) {
        bookName = name;
        head = nullptr;
    }

    // Add a student in priority order.
    // Priority 1 is highest, 2 is medium, and 3 is lowest.
    void addStudent(string name, int priority) {
        StudentNode* newNode = new StudentNode(name, priority);

        // If list is empty, or new student has higher priority, insert first.
        if (head == nullptr || priority < head->priority) {
            newNode->next = head;
            head = newNode;
        } else {
            StudentNode* temp = head;

            // Move past students with equal or higher priority.
            while (temp->next != nullptr && temp->next->priority <= priority) {
                temp = temp->next;
            }

            // Insert the new student after temp.
            newNode->next = temp->next;
            temp->next = newNode;
        }

        cout << name << " added to " << bookName << " reservation list." << endl;
    }

    // Remove a student from this book's reservation list.
    void removeStudent(string name) {
        if (head == nullptr) {
            cout << "Reservation list is empty." << endl;
            return;
        }

        // Special case: the student is at the front.
        if (head->studentName == name) {
            StudentNode* temp = head;
            head = head->next;
            delete temp;
            cout << name << " removed." << endl;
            return;
        }

        // Find the student while keeping temp at the previous node.
        StudentNode* temp = head;
        while (temp->next != nullptr && temp->next->studentName != name) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << "Student not found." << endl;
        } else {
            StudentNode* nodeToDelete = temp->next;
            temp->next = nodeToDelete->next;
            delete nodeToDelete;
            cout << name << " removed." << endl;
        }
    }

    // Change a student's priority and place them in the correct position again.
    void updatePriority(string name, int newPriority) {
        if (newPriority < 1 || newPriority > 3) {
            cout << "Priority must be 1, 2, or 3." << endl;
            return;
        }

        // First check whether the student exists.
        StudentNode* temp = head;
        while (temp != nullptr && temp->studentName != name) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Student not found." << endl;
            return;
        }

        // Remove the student, then add them again with the new priority.
        removeStudent(name);
        addStudent(name, newPriority);
        cout << "Priority updated for " << name << "." << endl;
    }

    // Display the waiting list for this particular book.
    void display() {
        cout << "\nReservations for " << bookName << ":" << endl;

        if (head == nullptr) {
            cout << "No students waiting." << endl;
            return;
        }

        StudentNode* temp = head;
        while (temp != nullptr) {
            cout << temp->studentName << " (Priority " << temp->priority << ")" << endl;
            temp = temp->next;
        }
    }

    // Count all students waiting for this book.
    void countStudents() {
        int count = 0;
        StudentNode* temp = head;

        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        cout << "Students waiting for " << bookName << ": " << count << endl;
    }

    // When the book is returned, give it to the first student and remove them.
    void bookReturned() {
        if (head == nullptr) {
            cout << "No reservation to serve for " << bookName << "." << endl;
            return;
        }

        StudentNode* temp = head;
        cout << "Book " << bookName << " is given to " << temp->studentName << "." << endl;

        head = head->next; // The next student becomes first.
        delete temp;       // Remove the student who received the book.
    }
};

int main() {
    // Each BookQueue object has its own separate linked list.
    BookQueue book1("C++ Programming");
    BookQueue book2("Data Structures");

    // Priority: 1 = Research, 2 = Assignment, 3 = Casual reading.
    book1.addStudent("Ali", 3);
    book1.addStudent("Sara", 1);
    book1.addStudent("Ahmed", 2);

    book2.addStudent("Hina", 2);
    book2.addStudent("Usman", 3);
    book2.addStudent("Ayesha", 1);

    book1.display();
    book2.display();

    // Ali's priority changes, so his position is updated.
    book1.updatePriority("Ali", 1);
    book1.display();

    // Usman cancels his reservation.
    book2.removeStudent("Usman");
    book2.display();

    book1.countStudents();
    book2.countStudents();

    // The first student in book1's list receives the returned book.
    book1.bookReturned();
    book1.display();

    return 0;
}
