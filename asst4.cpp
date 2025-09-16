//student id 1024030287
// asst4 q1
#include <iostream>
using namespace std;

#define N 5
int queue[N];
int front = -1;
int rear = -1;

void enqueue(int x) {
    if (rear == N - 1) {
        cout << "Overflow" << endl;
    }
    else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = x;
    }
    else {
        rear++;
        queue[rear] = x;
    }
}

void dequeue() {
    if (front == -1 && rear == -1) {
        cout << "Underflow" << endl;
    }
    else if (front == rear) {
        cout << "Dequeued: " << queue[front] << endl;
        front = rear = -1;
    }
    else {
        cout << "Dequeued: " << queue[front] << endl;
        front++;
    }
}

void display() {
    if (front == -1 && rear == -1) {
        cout << "Queue is empty" << endl;
    }
    else {
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
}

void peek() {
    if (front == -1 && rear == -1) {
        cout << "Underflow" << endl;
    }
    else {
        cout << "Front element: " << queue[front] << endl;
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    peek();
    dequeue();
    display();
    peek();
    dequeue();
    dequeue();
    
    return 0;
}
