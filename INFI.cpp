#include <iostream>
#include <string>
using namespace std;
#define MAX 100

struct Stack {
    char arr[MAX];
    int top;
};


void init(Stack &s) {
    s.top = -1;
}

bool isEmpty(Stack &s) {
    return s.top == -1;
}

bool isFull(Stack &s) {
    return s.top == MAX - 1;
}

void push(Stack &s, char x) {
    if (isFull(s)) {
        cout << "Stack Overflow\n";
    } else {
        s.arr[++s.top] = x;
        cout << x << " pushed\n";
    }
}

char pop(Stack &s) {
    if (isEmpty(s)) {
        cout << "Stack Underflow\n";
        return '\0';
    } else {
        return s.arr[s.top--];
    }
}

char peek(Stack &s) {
    if (isEmpty(s)) {
        cout << "Stack is empty\n";
        return '\0';
    }
    return s.arr[s.top];
}

void display(Stack &s) {
    if (isEmpty(s)) {
        cout << "Stack is empty\n";
        return;
    }
    cout << "Stack elements: ";
    for (int i = s.top; i >= 0; i--)
        cout << s.arr[i] << " ";
    cout << endl;
}

// Reverse string 
string reverseString(string str) {
    Stack s;
    init(s);

    for (char c : str) push(s, c);

    string rev = "";
    while (!isEmpty(s)) rev += pop(s);
    return rev;
}


bool isPalindrome(string str) {
    string rev = reverseString(str);
    return str == rev;
}

// Infix → postfix
int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3;
    return 0;
}

string infixToPostfix(string infix) {
    Stack s;
    init(s);
    string post = "";

    for (char c : infix) {
        if (isalnum(c)) post += c;
        else if (c == '(') push(s, c);
        else if (c == ')') {
            while (!isEmpty(s) && peek(s) != '(')
                post += pop(s);
            pop(s); 
        } else {
            while (!isEmpty(s) && precedence(peek(s)) >= precedence(c))
                post += pop(s);
            push(s, c);
        }
    }

    while (!isEmpty(s))
        post += pop(s);

    return post;
}

// Reverse string manually
string reverseStringManual(string s) {
    int n = s.length();
    for (int i = 0; i < n/2; i++)
        swap(s[i], s[n-i-1]);
    return s;
}

// Infix → prefix
string infixToPrefix(string infix) {
    string rev = reverseStringManual(infix);

    for (char &c : rev) {
        if (c == '(') c = ')';
        else if (c == ')') c = '(';
    }

    string post = infixToPostfix(rev);

    return reverseStringManual(post);
}

void decimalToBinary() {
    int stack[100];
    int top = -1;
    int num;
    cout << "Enter a decimal number: ";
    cin >> num;
    int n = num;
    while (n > 0) {
        stack[++top] = n % 2;
        n /= 2;
    }
    cout << "Binary of " << num << " = ";
    while (top >= 0)
        cout << stack[top--];
    cout << endl;
}

int main() {
    Stack s;
    init(s);

    int choice;
    string str, infix;

    do {
        cout << "   STACK MENU\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Reverse String\n";
        cout << "6. Check Palindrome\n";
        cout << "7. Infix to Postfix\n";
        cout << "8. Infix to Prefix\n";
        cout << "9. Decimal to Binary\n";
        cout << "10. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            char x;
            cout << "Enter element to push: ";
            cin >> x;
            push(s, x);
            break;
        }
        case 2:
            cout << "Popped: " << pop(s) << endl;
            break;
        case 3:
            cout << "Top element: " << peek(s) << endl;
            break;
        case 4:
            display(s);
            break;
        case 5:
            cout << "Enter string: ";
            cin >> str;
            cout << "Reversed: " << reverseString(str) << endl;
            break;
        case 6:
            cout << "Enter string: ";
            cin >> str;
            if (isPalindrome(str))
                cout << "It is a palindrome\n";
            else
                cout << "Not a palindrome\n";
            break;
        case 7:
            cout << "Enter infix expression: ";
            cin >> infix;
            cout << "Postfix: " << infixToPostfix(infix) << endl;
            break;
        case 8:
            cout << "Enter infix expression: ";
            cin >> infix;
            cout << "Prefix: " << infixToPrefix(infix) << endl;
            break;
          case 9: decimalToBinary(); break;

        case 10:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice\n";
        }
    } while (choice != 9);

    return 0;
}
