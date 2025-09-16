// 1024030287
// asst4 q2
#include <iostream>
using namespace std;

#define N 5
int queue[N];
int front = -1;
int rear = -1;

void enqueue(int x) {
    if ((rear + 1) % N == front) {
        cout << "Overflow (Queue is Full)" << endl;
    }
    else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = x;
    }
    else {
        rear = (rear + 1) % N;
        queue[rear] = x;
    }
}

void dequeue() {
    if (front == -1 && rear == -1) {
        cout << "Underflow (Queue is Empty)" << endl;
    }
    else if (front == rear) {
        cout << "Dequeued: " << queue[front] << endl;
        front = rear = -1;
    }
    else {
        cout << "Dequeued: " << queue[front] << endl;
        front = (front + 1) % N;
    }
}

void display() {
    if (front == -1 && rear == -1) {
        cout << "Queue is empty" << endl;
    }
    else {
        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << queue[i] << " ";
            if (i == rear) break;
            i = (i + 1) % N;
        }
        cout << endl;
    }
}

void peek() {
    if (front == -1 && rear == -1) {
        cout << "Underflow (Queue is Empty)" << endl;
    }
    else {
        cout << "Front element: " << queue[front] << endl;
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    display();
    dequeue();
    display();
    enqueue(50);
    display();
    peek();
    dequeue();
    dequeue();
    display();
    return 0;
}
