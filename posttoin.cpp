#include <iostream>
#include <stack>

using namespace std;

int main() {
    string str = "953+4*6/-";
    stack<string> st;

    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];
        int ascii = int(ch);

        if (ascii >= 48 && ascii <= 57) {
            string s = "";
            s += ch;
            st.push(s);
        } else {
            string v2 = st.top();
            st.pop();
            string v1 = st.top();
            st.pop();
            char o = ch;

            string t = "(" + v1 + o + v2 + ")";
            st.push(t);
        }
    }

    cout << st.top() << endl;

    return 0;
}
