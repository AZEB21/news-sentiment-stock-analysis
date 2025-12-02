#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}
string infixToPostfix(string infix) {
    stack<char> st;
    string result = "";

   for (int i = 0; i < infix.length(); i++) {
    char c = infix[i];
        if (isalnum(c)) {
            result += c;
        }
      
        else if (c == '(') {
            st.push(c);
        }
      
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop();
        }
        else { 
      
            while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    return result;
}
string infixToPrefix(string infix) {
    reverse(infix.begin(), infix.end());
    for (char &c : infix) {
        if (c == '(') c = ')';
        else if (c == ')') c = '(';
    }
    string postfix = infixToPostfix(infix);
    reverse(postfix.begin(), postfix.end());
    return postfix;
}
string postfixToInfix(string postfix) {
    stack<string> st;

    for (char c : postfix) {
        if (isalnum(c)) {
            st.push(string(1, c));
        }
        else {
            string b = st.top(); st.pop();
            string a = st.top(); st.pop();
            st.push("(" + a + c + b + ")");
        }
    }

    return st.top();
}


string prefixToInfix(string prefix) {
    stack<string> st;
    reverse(prefix.begin(), prefix.end());

    for (char c : prefix) {
        if (isalnum(c)) {
            st.push(string(1, c));
        }
        else {
            string a = st.top(); st.pop();
            string b = st.top(); st.pop();
            st.push("(" + a + c + b + ")");
        }
    }

    return st.top();
}


int main() {
    int choice;
    string exp;

    while (true) {
        cout << "\n===== EXPRESSION CONVERTER MENU =====\n";
        cout << "1. Infix to Postfix\n";
        cout << "2. Infix to Prefix\n";
        cout << "3. Postfix to Infix\n";
        cout << "4. Prefix to Infix\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 5) break;

        cout << "Enter Expression: ";
        cin >> exp;

        switch (choice) {
            case 1:
                cout << "Postfix: " << infixToPostfix(exp) << endl;
                break;

            case 2:
                cout << "Prefix: " << infixToPrefix(exp) << endl;
                break;

            case 3:
                cout << "Infix: " << postfixToInfix(exp) << endl;
                break;

            case 4:
                cout << "Infix: " << prefixToInfix(exp) << endl;
                break;

            default:
                cout << "Invalid choice!\n";
        }
    }

    return 0;
}
