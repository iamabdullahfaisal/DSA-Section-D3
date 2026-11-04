
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverseFirstK(queue<int>& q, int k) {
    int n = q.size();

    // Check invalid or unnecessary K
    if (k <= 1 || n == 0) {
        return;
    }

    // If K is greater than queue size
    if (k > n) {
        k = n;
    }

    stack<int> s;

    // Step 1: Push first K elements into stack
    for (int i = 0; i < k; i++) {
        s.push(q.front());
        q.pop();
    }

    // Step 2: Push stack elements back into queue
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    // Step 3: Move remaining elements to the back
    for (int i = 0; i < n - k; i++) {
        q.push(q.front());
        q.pop();
    }
}

// Display queue
void display(queue<int> q) {
    cout << "Queue: ";

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    cout << endl;
}

int main() {
    queue<int> q;
    int n, value, k;

    cout << "Enter number of elements: ";
    cin >> n;

    if (n < 0) {
        cout << "Invalid number of elements!" << endl;
        return 1;
    }

    // Input queue elements
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> value;
        q.push(value);
    }

    cout << "\nOriginal ";
    display(q);

    cout << "\nEnter K (number of elements to reverse): ";
    cin >> k;

    reverseFirstK(q, k);

    cout << "\nQueue after reversing first K elements:" << endl;
    display(q);

    return 0;
}
