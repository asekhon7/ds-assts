// 1024030287
// q5
#include <iostream>
using namespace std;

#define N 100

int q1[N], q2[N];
int front1 = -1, rear1 = -1, front2 = -1, rear2 = -1;

void enqueue1(int x) {
    if (rear1 == N - 1) { cout << "Overflow\n"; return; }
    if (front1 == -1 && rear1 == -1) front1 = rear1 = 0;
    else rear1++;
    q1[rear1] = x;
}

int dequeue1() {
    if (front1 == -1 && rear1 == -1) { return -1; }
    int val = q1[front1];
    if (front1 == rear1) front1 = rear1 = -1;
    else front1++;
    return val;
}

void enqueue2(int x) {
    if (rear2 == N - 1) { cout << "Overflow\n"; return; }
    if (front2 == -1 && rear2 == -1) front2 = rear2 = 0;
    else rear2++;
    q2[rear2] = x;
}

int dequeue2() {
    if (front2 == -1 && rear2 == -1) { return -1; }
    int val = q2[front2];
    if (front2 == rear2) front2 = rear2 = -1;
    else front2++;
    return val;
}

void push(int x) {
    enqueue2(x);
    while (front1 != -1) {
        enqueue2(dequeue1());
    }
    int tempFront = front1, tempRear = rear1;
    front1 = front2; rear1 = rear2;
    front2 = tempFront; rear2 = tempRear;
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

