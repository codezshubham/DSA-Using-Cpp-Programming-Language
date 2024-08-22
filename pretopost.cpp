#include <iostream>
#include <stack>

using namespace std;

int main() {
    string str = "-9/*+5346";
    stack<string> st;

    for (int i = str.length() - 1; i >= 0; i--) {
        char ch = str[i];
        int ascii = static_cast<int>(ch);

        if (ascii >= 48 && ascii <= 57) {
            string s = "";
            s += ch;
            st.push(s);
        } else {
            string v1 = st.top();
            st.pop();
            string v2 = st.top();
            st.pop();
            char o = ch;

            string t = v1 + v2 + o;
            st.push(t);
        }
    }

    cout << st.top() << endl;

    return 0;
}
