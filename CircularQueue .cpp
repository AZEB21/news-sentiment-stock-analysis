
#include <iostream>
using namespace std;

class CircularQueue
{
public:
    int arr[5];
    int front, rear;

    CircularQueue() { front = rear = -1; }

    bool isEmpty() { return front == -1; }
    bool isFull() { return (front == 0 && rear == 4) || (rear + 1 == front); }

    void enqueue(int x)
    {
        if (isFull())
        {
            cout << "CQueue FULL\n";
            return;
        }
        if (isEmpty())
            front = rear = 0;
        else
            rear = (rear + 1) % 5;
        arr[rear] = x;
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "CQueue EMPTY\n";
            return -1;
        }
        int val = arr[front];
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % 5;
        return val;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "CQueue empty\n";
            return;
        }
        int i = front;
        while (true)
        {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % 5;
        }
        cout << endl;
    }
};

int main()
{

    CircularQueue cq;

  int choice ,x;
    do{
        cout << "\n--- Circular Queue Menu ---\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Display\n";
        cout << "0. Exit\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> x;
            cq.enqueue(x);
            break;
       case 2:
             cout << "Removed: " << cq.dequeue() << endl;
             break;
        case 3:
             cq.display();
             break;
        
        default:
        cout<<"wrong choice";
            break;
        }
       
            
    }while(choice != 0);

    return 0;
}
