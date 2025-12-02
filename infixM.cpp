#include <iostream>
#include <cstring>
using namespace std;

#define MAX 100


struct Stack {
    char arr[MAX];
    int top;
};

void init(Stack &s) { s.top = -1; }

bool isEmpty(Stack &s) { return s.top == -1; }
bool isFull(Stack &s) { return s.top == MAX - 1; }

void push(Stack &s, char c) {
    if (isFull(s)) cout << "Stack Overflow\n";
    else s.arr[++s.top] = c;
}

char pop(Stack &s) {
    if (isEmpty(s)) return '#'; 
    else return s.arr[s.top--];
}

char peek(Stack &s) {
    if (isEmpty(s)) return '#';
    else return s.arr[s.top];
}



bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

void infixToPostfix(char infix[], char postfix[]) {
    Stack s;
    init(s);
    int k = 0; 
    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
            postfix[k++] = c;

        else if (c == '(')
            push(s, c);

        else if (c == ')') {
            while (!isEmpty(s) && peek(s) != '(')
                postfix[k++] = pop(s);
            pop(s); // remove '('
        }

        else if (isOperator(c)) {
            while (!isEmpty(s) && precedence(peek(s)) >= precedence(c))
                postfix[k++] = pop(s);
            push(s, c);
        }
    }

    while (!isEmpty(s))
        postfix[k++] = pop(s);

    postfix[k] = '\0';
}


// infix to Pre

void reverseString(char str[]) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

void swapParenthesis(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(') str[i] = ')';
        else if (str[i] == ')') str[i] = '(';
    }
}

void infixToPrefix(char infix[], char prefix[]) {
    reverseString(infix);
    swapParenthesis(infix);

    char temp[MAX];
    infixToPostfix(infix, temp);

    reverseString(temp);

    strcpy(prefix, temp);
}


int main() {
    int choice;
    char exp[MAX], result[MAX];

    while (true) {
        cout << "\n=== Expression Converter ===\n";
        cout << "1. Infix to Postfix\n";
        cout << "2. Infix to Prefix\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 3) break;

        cout << "Enter expression: ";
        cin >> exp;

        switch (choice) {
            case 1:
                infixToPostfix(exp, result);
                cout << "Postfix: " << result << endl;
                break;
            case 2:
                infixToPrefix(exp, result);
                cout << "Prefix: " << result << endl;
                break;
            default:
                cout << "Invalid choice!\n";
        }
    }

    return 0;
}
