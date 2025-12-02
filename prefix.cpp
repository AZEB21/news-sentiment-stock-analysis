#include <iostream>

using namespace std;
struct stack{
    int top;
    int maxsize;
   int *arr;

    };

    void init(stack &s, int size) {
    s.top = -1;
    s.maxsize = size;
    s.arr = new int[size];}


void push(stack &s, int x){
     if(s.top>= s.maxsize-1){
        cout<<"stack overflow\n";
     }
     else{
        s.arr[++s.top]=x;
        cout<<x<<" is pushed up.\n";
    }
}

void pop(stack &s){
    if(s.top==-1)
        cout<<"stack underflow\n";
    else{
        s.top--;
        cout<<"popped\n";
    }
}
int peek( stack &s){

    if(s.top==-1)
       { cout<<"stack is empty/stack underflow\n";
        return -1;}
    else
        return s.arr[s.top];

}
void display(stack &s) {
    if (s.top == -1) {
        cout << "Stack is empty.\n";
        return;
    }

    cout << "Stack elements (top to bottom): ";
    for (int i = s.top; i >= 0; i--) {
        cout << s.arr[i] << " ";
    }
    cout << endl;
}

int main(){
    stack s;
    int choice,val,n;
    cout<<"enter the array size\n";
    cin >> n;
   init(s, n);

    do{
        cout<<"1.push\n";
        cout<<"2.pop\n";
        cout<<"3.peek\n";
        cout<<"4.display\n";
        cout<<"5.exit\n";
        cout<<"enter your choice:\n";
        cin>>choice;
        switch(choice){
    case 1:
        cout<<"enter value to push\n";
        cin>>val;
        push(s,val);
        //display(s);
        break;
    case 2:
        pop(s);
        break;

    case 3:
        val=peek(s);
        if(val !=-1)
            cout<<"Top element is:"<<val<<endl;
        break;
    case 4:
        display(s);
        break;
    case 5:
        cout<<"exit\n";
         break;
    default:
            cout<<"invalid choice\n";


       }
    }while(choice!=5);

    return 0;
}