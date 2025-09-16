// 1024030287
// q4
#include <iostream>
using namespace std;

#define N 100

char q[N];
int front = -1, rear = -1;

// Enqueue
void enqueue(char x) {
    if (rear == N - 1) {
        cout << "Overflow\n";
        return;
    }
    if (front == -1 && rear == -1) {
        front = rear = 0;
    } else {
        rear++;
    }
    q[rear] = x;
}

// Dequeue
void dequeue() {
    if (front == -1 && rear == -1) {
        cout << "Underflow\n";
        return;
    }
    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
}

// Peek (front element)
char peek() {
    if (front == -1 && rear == -1) {
        return '\0';  // null character if empty
    }
    return q[front];
}

// Display queue (not needed for logic, but matches your style)
void display() {
    if (front == -1 && rear == -1) {
        cout << "Queue is empty\n";
        return;
    }
    for (int i = front; i <= rear; i++) {
        cout << q[i] << " ";
    }
    cout << "\n";
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    int freq[26] = {0};

    cout << "Output: ";
    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];

        enqueue(ch);
        freq[ch - 'a']++;

        // remove all repeating chars from queue front
        while (front != -1 && freq[peek() - 'a'] > 1) {
            dequeue();
        }

        if (front == -1) cout << -1 << " ";
        else cout << peek() << " ";
    }

    cout << "\n";
    return 0;
}
