#include <iostream>
#include <stack>
using namespace std;

int evaluateExpression(string& str) {
    stack<int> st;
    stack<char> op;

    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];
        int ascii = int(ch);

        if (ascii >= 48 && ascii <= 57) {
            st.push(ascii - 48);
        } else if (op.empty() || ch == '(' || op.top() == '(') {
            op.push(ch);
        } else if (ch == ')') {
            while (op.top() != '(') {
                int v2 = st.top();
                st.pop();
                int v1 = st.top();
                st.pop();
                if (op.top() == '-')
                    st.push(v1 - v2);
                else if (op.top() == '+')
                    st.push(v1 + v2);
                else if (op.top() == '*')
                    st.push(v1 * v2);
                else if (op.top() == '/')
                    st.push(v1 / v2);
                op.pop();
            }
            op.pop(); // Pop this '('
        } else {
            if (ch == '+' || ch == '-') {
                int v2 = st.top();
                st.pop();
                int v1 = st.top();
                st.pop();
                if (op.top() == '-')
                    st.push(v1 - v2);
                else if (op.top() == '+')
                    st.push(v1 + v2);
                else if (op.top() == '*')
                    st.push(v1 * v2);
                else if (op.top() == '/')
                    st.push(v1 / v2);
                op.pop();
                op.push(ch);
            } else if (ch == '*' || ch == '/') {
                if (op.top() == '*' || op.top() == '/') {
                    int v2 = st.top();
                    st.pop();
                    int v1 = st.top();
                    st.pop();
                    if (op.top() == '*')
                        st.push(v1 * v2);
                    else if (op.top() == '/')
                        st.push(v1 / v2);
                    op.pop();
                    op.push(ch);
                } else {
                    op.push(ch);
                }
            }
        }
    }

    while (!st.empty() && !op.empty()) {
        int v2 = st.top();
        st.pop();
        int v1 = st.top();
        st.pop();
        if (op.top() == '-')
            st.push(v1 - v2);
        else if (op.top() == '+')
            st.push(v1 + v2);
        else if (op.top() == '*')
            st.push(v1 * v2);
        else if (op.top() == '/')
            st.push(v1 / v2);
        op.pop();
    }

    return st.top();
}

int main() {
    string str = "9-(5+3)*4/6";
    cout << evaluateExpression(str) << endl;

    return 0;
}
