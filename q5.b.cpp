#include <iostream>
using namespace std;

#define N 100

int q[N];
int front1 = -1, rear1 = -1;

void enqueue1(int x) {
    if (rear1 == N - 1) { cout << "Overflow\n"; return; }
    if (front1 == -1 && rear1 == -1) front1 = rear1 = 0;
    else rear1++;
    q[rear1] = x;
}

int dequeue1() {
    if (front1 == -1 && rear1 == -1) { return -1; }
    int val = q[front1];
    if (front1 == rear1) front1 = rear1 = -1;
    else front1++;
    return val;
}

void push(int x) {
    enqueue1(x);
    int size = rear1 - front1 + 1;
    for (int i = 1; i < size; i++) {
        enqueue1(dequeue1());
    }
}

int pop() {
    if (front1 == -1 && rear1 == -1) {
        cout << "Stack Empty\n";
        return -1;
    }
    return dequeue1();
}

int main() {
    push(10);
    push(20);
    push(30);

    cout << pop() << "\n";
    cout << pop() << "\n";
    cout << pop() << "\n";
    cout << pop() << "\n";

    return 0;
}
