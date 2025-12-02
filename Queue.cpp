#include <iostream>
using namespace std;

class ArrayStack {
    int top;
    int arr[100];
public:
    ArrayStack(){ top = -1; }

    void push(int x){
      
        if(top == 99){
            cout << "Stack Overflow!\n";
            return;
        }
        top++;
        arr[top] = x;
    }

    int pop(){
       
        if(top == -1){
            cout << "Stack Underflow!\n";
            return -1;
        }
        int val = arr[top];
        top--;
        return val;
    }

    void display(){
        if(top == -1){ cout<<"Stack empty\n"; return; }
        cout<<"Stack (top -> bottom): ";
        for(int i=top; i>=0; i--) cout<<arr[i]<<" ";
        cout<<endl;
    }
};
struct Node{
    int data;
    Node* next;
};

class LinkedListStack {
    Node* top;
public:
    LinkedListStack(){ top = NULL; }

    void push(int x){
        Node* n = new Node;
        n->data = x;
        n->next = top;  // new node points to old top
        top = n;        // move top
    }

    int pop(){
        if(top == NULL){
            cout<<"Stack Underflow!\n";
            return -1;
        }
        int val = top->data;
        Node* temp = top;
        top = top->next; // move top down
        delete temp;
        return val;
    }

    void display(){
        if(top == NULL){ cout<<"Stack empty\n"; return; }
        Node* t = top;
        cout<<"Linked Stack (top -> bottom): ";
        while(t){
            cout<<t->data<<" ";
            t = t->next;
        }
        cout<<endl;
    }
};


class Queue {
    int arr[100];
    int front, rear;
public:
    Queue(){
        front = rear = -1;
    }

    void enqueue(int x){
        if(rear == 99){
            cout<<"Queue Overflow!\n";
            return;
        }
        if(front == -1) 
        front = 0;  
        rear++;
        arr[rear] = x;
    }

    int dequeue(){
        if(front == -1 || front > rear){
            cout<<"Queue Underflow!\n";
            return -1;
        }
        return arr[front++];
    }

    void display(){
        if(front == -1 || front > rear){
            cout<<"Queue empty\n";
            return;
        }
        cout<<"Queue (front -> rear): ";
        for(int i=front; i<=rear; i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
};


int main(){
    ArrayStack s1;
    LinkedListStack s2;
    Queue q;

    int choice, value;

    while(true){
        cout<<"\n===== MENU =====\n";
        cout<<"1. Push (Array Stack)\n";
        cout<<"2. Pop (Array Stack)\n";
        cout<<"3. Display Array Stack\n";
        cout<<"4. Push (Linked Stack)\n";
        cout<<"5. Pop (Linked Stack)\n";
        cout<<"6. Display Linked Stack\n";
        cout<<"7. Enqueue (Queue)\n";
        cout<<"8. Dequeue (Queue)\n";
        cout<<"9. Display Queue\n";
        cout<<"0. Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;

        switch(choice){
        case 1:
            cout<<"Enter value: ";
            cin>>value;
            s1.push(value);
            break;

        case 2:
            cout<<"Popped: "<<s1.pop()<<endl;
            break;

        case 3:
            s1.display();
            break;

        case 4:
            cout<<"Enter value: ";
            cin>>value;
            s2.push(value);
            break;

        case 5:
            cout<<"Popped: "<<s2.pop()<<endl;
            break;

        case 6:
            s2.display();
            break;

        case 7:
            cout<<"Enter value: ";
            cin>>value;
            q.enqueue(value);
            break;

        case 8:
            cout<<"Dequeued: "<<q.dequeue()<<endl;
            break;

        case 9:
            q.display();
            break;

        case 0:
            return 0;

        default:
            cout<<"Invalid choice\n";
        }
    }
}
