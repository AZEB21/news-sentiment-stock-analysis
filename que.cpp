
#include <iostream>
using namespace std;
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
  
    Queue q;

    int choice, value;

    while(true){
        cout<<"\n===== MENU =====\n";
       
        cout<<"1. Enqueue (Queue)\n";
        cout<<"2. Dequeue (Queue)\n";
        cout<<"3. Display Queue\n";
        cout<<"0. Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;

        switch(choice){
        

        case 1:
            cout<<"Enter value: ";
            cin>>value;
            q.enqueue(value);
            break;

        case 2:
            cout<<"Dequeued: "<<q.dequeue()<<endl;
            break;

        case 3:
            q.display();
            break;

        case 0:
            return 0;

        default:
            cout<<"Invalid choice\n";
        }
    }
}
