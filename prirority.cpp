#include <iostream>
#include <string>
using namespace std;


struct DeNode {
    int data;
    DeNode *prev, *next;
};

class DoubleEndedQueue {
private:
    DeNode *front, *rear;

public:
    DoubleEndedQueue() {
        front = rear = NULL;
    }

    bool isEmpty() {
        return front == NULL;
    }

    void insertFront(int x) {
        DeNode *temp = new DeNode{x, NULL, NULL};
        if (isEmpty()) {
            front = rear = temp;
        } else {
            temp->next = front;
            front->prev = temp;
            front = temp;
        }
        cout << "Inserted at front.\n";
    }

    void insertRear(int x) {
        DeNode *temp = new DeNode{x, NULL, NULL};
        if (isEmpty()) {
            front = rear = temp;
        } else {
            rear->next = temp;
            temp->prev = rear;
            rear = temp;
        }
        cout << "Inserted at rear.\n";
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is empty!\n";
            return;
        }
        DeNode *temp = front;
        front = front->next;
        if (front) front->prev = NULL;
        else rear = NULL;
        delete temp;
        cout << "Front deleted.\n";
    }

    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is empty!\n";
            return;
        }
        DeNode *temp = rear;
        rear = rear->prev;
        if (rear) rear->next = NULL;
        else front = NULL;
        delete temp;
        cout << "Rear deleted.\n";
    }

    void display() {
        if (isEmpty()) {
            cout << "Deque is empty!\n";
            return;
        }
        DeNode *t = front;
        cout << "Deque: ";
        while (t) {
            cout << t->data << " ";
            t = t->next;
        }
        cout << "\n";
    }
};




struct Person {
    string name;
    string gender;  // "male" or "female"
    Person *next;
};

class FemalePriorityQueue {
private:
    Person *front;

public:
    FemalePriorityQueue() {
        front = NULL;
    }

    // FEMALE has highest priority
    void insert(string name, string gender) {
        Person *temp = new Person{name, gender, NULL};

        if (front == NULL || gender == "female") {
            temp->next = front;
            front = temp;
        } else {
            Person *t = front;
            while (t->next != NULL && t->next->gender != "female") {
                t = t->next;
            }
            temp->next = t->next;
            t->next = temp;
        }

        cout << "Inserted into female priority queue.\n";
    }

    void remove() {
        if (front == NULL) {
            cout << "Queue empty!\n";
            return;
        }
        Person *temp = front;
        front = front->next;
        delete temp;
        cout << "Removed highest priority.\n";
    }

    void display() {
        if (front == NULL) {
            cout << "Queue empty!\n";
            return;
        }
        cout << "Queue: \n";
        Person *t = front;
        while (t) {
            cout << "Name: " << t->name 
                 << " | Gender: " << t->gender << "\n";
            t = t->next;
        }
    }
};



struct AgePerson {
    string name;
    int age;
    AgePerson *next;
};

class AgePriorityQueue {
private:
    AgePerson *front;

public:
    AgePriorityQueue() {
        front = NULL;
    }

    void insert(string name, int age) {
        AgePerson *temp = new AgePerson{name, age, NULL};

        if (front == NULL || age > front->age) {
            temp->next = front;
            front = temp;
        } else {
            AgePerson *t = front;
            while (t->next != NULL && t->next->age >= age) {
                t = t->next;
            }
            temp->next = t->next;
            t->next = temp;
        }

        cout << "Inserted by age priority.\n";
    }

    void remove() {
        if (front == NULL) {
            cout << "Queue empty!\n";
            return;
        }
        AgePerson *temp = front;
        front = front->next;
        delete temp;
        cout << "Removed highest age priority.\n";
    }

    void display() {
        if (front == NULL) {
            cout << "Queue empty!\n";
            return;
        }
        cout << "Queue by age: \n";
        AgePerson *t = front;
        while (t) {
            cout << "Name: " << t->name 
                 << " | Age: " << t->age << "\n";
            t = t->next;
        }
    }
};



int main() {
    DoubleEndedQueue dq;
    FemalePriorityQueue fpq;
    AgePriorityQueue apq;

    int choice;

    while (true) {
        cout << "\n=============================\n";
        cout << "         MAIN MENU\n";
        cout << "=============================\n";
        cout << "1. Double Ended Queue\n";
        cout << "2. Female Priority Queue\n";
        cout << "3. Age Priority Queue\n";
        cout << "4. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        if (choice == 1) {
            int c, x;
            while (true) {
                cout << "\n--- DOUBLE ENDED QUEUE ---\n";
                cout << "1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Display\n6. Back\nChoose: ";
                cin >> c;

                if (c == 1) { cout << "Enter value: "; cin >> x; dq.insertFront(x); }
                else if (c == 2) { cout << "Enter value: "; cin >> x; dq.insertRear(x); }
                else if (c == 3) dq.deleteFront();
                else if (c == 4) dq.deleteRear();
                else if (c == 5) dq.display();
                else break;
            }
        }

        else if (choice == 2) {
            int c;
            string name, gender;

            while (true) {
                cout << "\n--- FEMALE PRIORITY QUEUE ---\n";
                cout << "1. Insert\n2. Remove\n3. Display\n4. Back\nChoose: ";
                cin >> c;

                if (c == 1) {
                    cout << "Enter name: "; cin >> name;
                    cout << "Enter gender (male/female): "; cin >> gender;
                    fpq.insert(name, gender);
                }
                else if (c == 2) fpq.remove();
                else if (c == 3) fpq.display();
                else break;
            }
        }

        else if (choice == 3) {
            int c, age;
            string name;

            while (true) {
                cout << "\n--- AGE PRIORITY QUEUE ---\n";
                cout << "1. Insert\n2. Remove\n3. Display\n4. Back\nChoose: ";
                cin >> c;

                if (c == 1) {
                    cout << "Enter name: "; cin >> name;
                    cout << "Enter age: "; cin >> age;
                    apq.insert(name, age);
                }
                else if (c == 2) apq.remove();
                else if (c == 3) apq.display();
                else break;
            }
        }

        else break;
    }

    return 0;
}
