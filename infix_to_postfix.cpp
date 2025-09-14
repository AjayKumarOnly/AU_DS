#include <iostream>
#include <stack>
#include <cctype>
#include <string>
#include <cmath>
using namespace std;

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return -1;
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string infixToPostfix(const string &infix) {
    stack<char> st;
    string postfix;

    for (char c : infix) {
        if (isspace(c)) continue; 

        if (isalnum(c)) {
            postfix += c;
        }
        else if (c == '(') {
            st.push(c);
        }
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop();
        }
        else if (isOperator(c)) {
            while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                if (c == '^' && st.top() == '^') break;
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
  
    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }
    return postfix;
}

int evaluatePostfix(const string &postfix) {
    stack<int> st;

    for (char c : postfix) {
        if (isdigit(c)) {
            st.push(c - '0'); 
        }
        else if (isOperator(c)) {
            int val2 = st.top(); st.pop();
            int val1 = st.top(); st.pop();
            switch (c) {
                case '+': st.push(val1 + val2); break;
                case '-': st.push(val1 - val2); break;
                case '*': st.push(val1 * val2); break;
                case '/': st.push(val1 / val2); break;
                case '^': st.push(pow(val1, val2)); break;
            }
        }
    }
    return st.top();
}

int main() {
    string infix;
    cout << "Enter infix expression (single-digit operands): ";
    getline(cin, infix);

    string postfix = infixToPostfix(infix);
    cout << "Postfix Expression: " << postfix << endl;

    int result = evaluatePostfix(postfix);
    cout << "Evaluation Result: " << result << endl;

    return 0;
}
