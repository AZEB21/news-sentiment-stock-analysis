#include <iostream>
using namespace std;

/*-------------------------------------------------
   1. NORMAL QUEUE (FIFO)
--------------------------------------------------*/
class Queue {
public:
    int arr[5];
    int front, rear;

    Queue() { front = rear = -1; }

    bool isEmpty() { return front == -1; }
    bool isFull()  { return rear == 4; }

    void enqueue(int x) {
        if (isFull()) { cout << "Queue FULL\n"; return; }
        if (isEmpty()) front = 0;
        arr[++rear] = x;
    }

    int dequeue() {
        if (isEmpty()) { cout << "Queue EMPTY\n"; return -1; }
        int val = arr[front];
        if (front == rear) front = rear = -1;
        else front++;
        return val;
    }

    void display() {
        if (isEmpty()) { cout << "Queue empty\n"; return; }
        for (int i = front; i <= rear; i++) cout << arr[i] << " ";
        cout << endl;
    }
};


class CircularQueue {
public:
    int arr[5];
    int front, rear;

    CircularQueue() { front = rear = -1; }

    bool isEmpty() { return front == -1; }
    bool isFull()  { return (front == 0 && rear == 4) || (rear + 1 == front); }

    void enqueue(int x) {
        if (isFull()) { cout << "CQueue FULL\n"; return; }
        if (isEmpty()) front = rear = 0;
        else rear = (rear + 1) % 5;
        arr[rear] = x;
    }

    int dequeue() {
        if (isEmpty()) { cout << "CQueue EMPTY\n"; return -1; }
        int val = arr[front];
        if (front == rear) front = rear = -1;
        else front = (front + 1) % 5;
        return val;
    }

    void display() {
        if (isEmpty()) { cout << "CQueue empty\n"; return; }
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % 5;
        }
        cout << endl;
    }
};

/*-------------------------------------------------
   3. STACK (LIFO)
--------------------------------------------------*/
class Stack {
public:
    int arr[5];
    int top;

    Stack() { top = -1; }

    bool isEmpty() { return top == -1; }
    bool isFull()  { return top == 4; }

    void push(int x) {
        if (isFull()) { cout << "Stack FULL\n"; return; }
        arr[++top] = x;
    }

    int pop() {
        if (isEmpty()) { cout << "Stack EMPTY\n"; return -1; }
        return arr[top--];
    }

    void display() {
        if (isEmpty()) { cout << "Stack empty\n"; return; }
        for (int i = 0; i <= top; i++) cout << arr[i] << " ";
        cout << endl;
    }
};
class DequeClass {
public:
    int arr[5];
    int front, rear;

    DequeClass() { front = rear = -1; }

    bool isEmpty() { return front == -1; }
    bool isFull()  { return (front == 0 && rear == 4) || (rear + 1 == front); }

    void push_front(int x) {
        if (isFull()) { cout << "Deque FULL\n"; return; }
        if (isEmpty()) front = rear = 0;
        else if (front == 0) front = 4;
        else front--;
        arr[front] = x;
    }

    void push_back(int x) {
        if (isFull()) { cout << "Deque FULL\n"; return; }
        if (isEmpty()) front = rear = 0;
        else rear = (rear + 1) % 5;
        arr[rear] = x;
    }

    int pop_front() {
        if (isEmpty()) { cout << "Deque EMPTY\n"; return -1; }
        int val = arr[front];
        if (front == rear) front = rear = -1;
        else front = (front + 1) % 5;
        return val;
    }

    int pop_back() {
        if (isEmpty()) { cout << "Deque EMPTY\n"; return -1; }
        int val = arr[rear];
        if (front == rear) front = rear = -1;
        else if (rear == 0) rear = 4;
        else rear--;
        return val;
    }

    void display() {
        if (isEmpty()) { cout << "Deque empty\n"; return; }
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % 5;
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    CircularQueue cq;
    Stack s;
    DequeClass d;

    int choice, sub, x;

    while (true) {
        cout << "\n===== MAIN MENU =====\n";
        cout << "1. Queue\n";
        cout << "2. Circular Queue\n";
        cout << "3. Stack\n";
        cout << "4. Deque\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 5) break;

        switch (choice) {

      
        case 1:
            cout << "\n--- Queue Menu ---\n";
            cout << "1. Enqueue\n2. Dequeue\n3. Display\n";
            cin >> sub;

            if (sub == 1) { cout << "Enter value: "; cin >> x; q.enqueue(x); }
            else if (sub == 2) cout << "Removed: " << q.dequeue() << endl;
            else q.display();
            break;

        case 2:
            cout << "\n--- Circular Queue Menu ---\n";
            cout << "1. Enqueue\n2. Dequeue\n3. Display\n";
            cin >> sub;

            if (sub == 1) { cout << "Enter value: "; cin >> x; cq.enqueue(x); }
            else if (sub == 2) cout << "Removed: " << cq.dequeue() << endl;
            else cq.display();
            break;

        /*-------------------- STACK ----------------------*/
        case 3:
            cout << "\n--- Stack Menu ---\n";
            cout << "1. Push\n2. Pop\n3. Display\n";
            cin >> sub;

            if (sub == 1) { cout << "Enter value: "; cin >> x; s.push(x); }
            else if (sub == 2) cout << "Removed: " << s.pop() << endl;
            else s.display();
            break;

        /*-------------------- DEQUE ----------------------*/
        case 4:
            cout << "\n--- Deque Menu ---\n";
            cout << "1. Push Front\n2. Push Back\n3. Pop Front\n4. Pop Back\n5. Display\n";
            cin >> sub;

            if (sub == 1) { cout << "Enter value: "; cin >> x; d.push_front(x); }
            else if (sub == 2) { cout << "Enter value: "; cin >> x; d.push_back(x); }
            else if (sub == 3) cout << "Removed: " << d.pop_front() << endl;
            else if (sub == 4) cout << "Removed: " << d.pop_back() << endl;
            else d.display();
            break;

        default:
            cout << "Invalid choice\n";
        }
    }

    cout << "\nGoodbye Az! 💛\n";
    return 0;
}
