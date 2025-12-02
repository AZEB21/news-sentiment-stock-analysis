#include <iostream>
#include <string>
#include <limits>
using namespace std;

#define MAX_SIZE 100

int arrStack[MAX_SIZE];
int topArray = -1;

bool isEmptyArray() {
    return topArray == -1;
}

void pushArray(int item) {
    if (topArray >= MAX_SIZE - 1)
        cout << "Stack Overflow!\n";
    else {
        arrStack[++topArray] = item;
        cout << "Item added to stack.\n";
    }
}

void popArray() {
    if (isEmptyArray())
        cout << "Stack Underflow!\n";
    else
        cout << "Popped item: " << arrStack[topArray--] << endl;
}

void peekArray() {
    if (isEmptyArray())
        cout << "Stack is empty!\n";
    else
        cout << "Top element: " << arrStack[topArray] << endl;
}

void displayArray() {
    if (isEmptyArray())
        cout << "Stack is empty!\n";
    else {
        cout << "Stack (top to bottom): ";
        for (int i = topArray; i >= 0; i--)
            cout << arrStack[i] << " ";
        cout << endl;
    }
}

struct Node {
    int data;
    Node* next;
};

Node* topLinked = NULL;

bool isEmptyLinked() {
    return topLinked == NULL;
}

void pushLinked(int item) {
    Node* newNode = new Node;
    newNode->data = item;
    newNode->next = topLinked;
    topLinked = newNode;
    cout << "Item added to linked stack.\n";
}

void popLinked() {
    if (isEmptyLinked())
        cout << "Stack is empty!\n";
    else {
        Node* temp = topLinked;
        cout << "Popped item: " << temp->data << endl;
        topLinked = topLinked->next;
        delete temp;
    }
}

void peekLinked() {
    if (isEmptyLinked())
        cout << "Stack is empty!\n";
    else
        cout << "Top element: " << topLinked->data << endl;
}

void displayLinked() {
    if (isEmptyLinked())
        cout << "Stack is empty!\n";
    else {
        cout << "Stack (top to bottom): ";
        Node* temp = topLinked;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

void reverseString() {
    char stack[100];
    int top = -1;
    string str;
    cout << "Enter a string: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, str);
    for (char c : str)
        stack[++top] = c;
    cout << "Reversed string: ";
    while (top >= 0)
        cout << stack[top--];
    cout << endl;
}

void checkPalindrome() {
    char stack[100];
    int top = -1;
    string str;
    cout << "Enter a string: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, str);
    for (char c : str)
        stack[++top] = c;
    bool isPalindrome = true;
    for (int i = 0; i < str.length(); i++) {
        if (stack[top--] != str[i]) {
            isPalindrome = false;
            break;
        }
    }
    if (isPalindrome)
        cout << "Palindrome!\n";
    else
        cout << "Not a palindrome!\n";
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
    int choice, value;
    while (true) {
        cout << "\n========= STACK MENU =========\n";
        cout << "1. Push (Array)\n";
        cout << "2. Pop (Array)\n";
        cout << "3. Peek (Array)\n";
        cout << "4. Display (Array)\n";
        cout << "5. Push (Linked)\n";
        cout << "6. Pop (Linked)\n";
        cout << "7. Peek (Linked)\n";
        cout << "8. Display (Linked)\n";
        cout << "9. Reverse a String\n";
        cout << "10. Check Palindrome\n";
        cout << "11. Decimal to Binary\n";
        cout << "0. Exit\n";
        cout << "===============================\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                pushArray(value);
                break;
            case 2: popArray(); break;
            case 3: peekArray(); break;
            case 4: displayArray(); break;
            case 5:
                cout << "Enter value: ";
                cin >> value;
                pushLinked(value);
                break;
            case 6: popLinked(); break;
            case 7: peekLinked(); break;
            case 8: displayLinked(); break;
            case 9: reverseString(); break;
            case 10: checkPalindrome(); break;
            case 11: decimalToBinary(); break;
            case 0:
                cout << "Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}