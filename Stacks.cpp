#include <iostream>
using namespace std;

/* ============================================================
      SUMMARY OF CHAPTER 5 — STACKS + QUEUES
   ============================================================ */

/* ---------------- STACK USING ARRAY (LIFO) ---------------- */
const int MAX = 50;
int stackArr[MAX];
int topArr = -1;

// PUSH = insert at TOP
void pushArray(int x) {
    if (topArr == MAX - 1) {
        cout << "Stack Overflow (No space)\n";
    } else {
        stackArr[++topArr] = x;   // increment top then insert
        cout << "Pushed " << x << endl;
    }
}

// POP = remove from TOP
int popArray() {
    if (topArr == -1) {
        cout << "Stack Underflow (Empty)\n";
        return -1;
    } else {
        return stackArr[topArr--];  // return top then decrease
    }
}

/* ---------------- STACK USING LINKED LIST ---------------- */
struct Node {
    int data;
    Node *next;
};
Node *topList = NULL;

// PUSH = add new node at TOP
void pushList(int x) {
    Node *newNode = new Node;
    newNode->data = x;
    newNode->next = topList;
    topList = newNode;
    cout << "Pushed " << x << " into Linked List Stack\n";
}

// POP = remove TOP node
int popList() {
    if (topList == NULL) {
        cout << "Underflow (Empty Stack)\n";
        return -1;
    }
    int val = topList->data;
    Node *temp = topList;
    topList = topList->next;
    delete temp;
    return val;
}

/* ---------------- SIMPLE QUEUE USING ARRAY (FIFO) ---------------- */
int queueArr[MAX];
int FRONT = -1, REAR = -1;

// ENQUEUE = insert at REAR
void enqueue(int x) {
    if (REAR == MAX - 1) {
        cout << "Queue Overflow\n";
        return;
    }
    if (FRONT == -1) FRONT = 0; // first element
    queueArr[++REAR] = x;
    cout << "Enqueued " << x << endl;
}

// DEQUEUE = remove from FRONT
int dequeue() {
    if (FRONT == -1 || FRONT > REAR) {
        cout << "Queue Underflow\n";
        return -1;
    }
    return queueArr[FRONT++];
}

/* -------------------- DISPLAY FUNCTIONS ------------------- */
void displayStackArray() {
    if (topArr == -1) {
        cout << "Stack Empty\n";
        return;
    }
    cout << "Stack (Array): ";
    for (int i = topArr; i >= 0; i--)
        cout << stackArr[i] << " ";
    cout << endl;
}

void displayStackList() {
    Node *temp = topList;
    if (!temp) { cout << "Stack Empty\n"; return; }
    cout << "Stack (Linked List): ";
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void displayQueue() {
    if (FRONT == -1 || FRONT > REAR) {
        cout << "Queue Empty\n";
        return;
    }
    cout << "Queue: ";
    for (int i = FRONT; i <= REAR; i++)
        cout << queueArr[i] << " ";
    cout << endl;
}

/* =============================== MENU ================================ */
int main() {
    int choice, value;

    while (true) {
        cout << "\n================ MAIN MENU ================\n";
        cout << "1. Stack (Array) - PUSH\n";
        cout << "2. Stack (Array) - POP\n";
        cout << "3. Stack (Linked List) - PUSH\n";
        cout << "4. Stack (Linked List) - POP\n";
        cout << "5. Queue (Array) - ENQUEUE\n";
        cout << "6. Queue (Array) - DEQUEUE\n";
        cout << "7. Display Stack (Array)\n";
        cout << "8. Display Stack (List)\n";
        cout << "9. Display Queue\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                pushArray(value);
                break;
            case 2:
                cout << "Popped: " << popArray() << endl;
                break;
            case 3:
                cout << "Enter value: ";
                cin >> value;
                pushList(value);
                break;
            case 4:
                cout << "Popped: " << popList() << endl;
                break;
            case 5:
                cout << "Enter value: ";
                cin >> value;
                enqueue(value);
                break;
            case 6:
                cout << "Dequeued: " << dequeue() << endl;
                break;
            case 7:
                displayStackArray();
                break;
            case 8:
                displayStackList();
                break;
            case 9:
                displayQueue();
                break;
            case 0:
                cout << "Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }
}
