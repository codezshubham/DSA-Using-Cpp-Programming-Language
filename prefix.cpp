#include <iostream>
#include <stack>
using namespace std;

int evaluatePrefix(const string& str) {
    stack<int> st;

    for (int i = str.length() - 1; i >= 0; i--) {
        char ch = str[i];
        int ascii = static_cast<int>(ch);

        if (ascii >= 48 && ascii <= 57) {
            st.push(ascii - 48);
        } else {
            int v1 = st.top();
            st.pop();
            int v2 = st.top();
            st.pop();
            if (ch == '+') st.push(v1 + v2);
            if (ch == '-') st.push(v1 - v2);
            if (ch == '*') st.push(v1 * v2);
            if (ch == '/') st.push(v1 / v2);
        }
    }

    return st.top();
}

int main() {
    string str = "-9/*+5346";
    cout << evaluatePrefix(str) << endl;

    return 0;
}
