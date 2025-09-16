// student id 1024030287
// asst 4 q3
#include <iostream>
using namespace std;

#define SIZE 100

int q[SIZE];
int front = -1, rear = -1;

// Enqueue
void enqueue(int x) {
    if (rear == SIZE - 1) {
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
int dequeue() {
    if (front == -1 && rear == -1) {
        cout << "Underflow\n";
        return -1;
    }
    int val = q[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
    return val;
}

// Peek
int peek() {
    if (front == -1 && rear == -1) {
        cout << "Underflow\n";
        return -1;
    }
    return q[front];
}

// Display
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
    int n;
    cout << "Enter even number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        enqueue(arr[i]);
    }

    int half = n / 2;

    cout << "Interleaved Queue: ";
    for (int i = 0; i < half; i++) {
        cout << arr[i] << " " << arr[i + half] << " ";
    }
    cout << "\n";

    return 0;
}
