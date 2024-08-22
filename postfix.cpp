#include <iostream>
#include <stack>
using namespace std;

int evaluatePostfix(const string& str) {
    stack<int> st;

    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];
        int ascii = int(ch);

        if (ascii >= 48 && ascii <= 57) {
            st.push(ascii - 48);
        } else {
            int v2 = st.top();
            st.pop();
            int v1 = st.top();
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
    string str = "953+4*6/-";
    cout << evaluatePostfix(str) << endl;

    return 0;
}
