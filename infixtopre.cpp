#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string str = "9-(5+3)*4/6";
    stack<string> st;
    stack<char> op;

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        int ascii = static_cast<int>(ch);

        if (ascii >= 48 && ascii <= 57)
        { // 0 to 9
            string s = "";
            s += ch;
            st.push(s);
        }
        else if (op.size() == 0 || ch == '(' || op.top() == '(')
        {
            op.push(ch);
        }
        else if (ch == ')')
        {
            while (op.top() != '(')
            {
                string v2 = st.top();
                st.pop();
                string v1 = st.top();
                st.pop();
                char o = op.top();
                op.pop();
                string t = o + v1 + v2;
                st.push(t);
            }
            op.pop(); // Pop this '('
        }
        else
        {
            if (ch == '+' || ch == '-')
            {
                string v2 = st.top();
                st.pop();
                string v1 = st.top();
                st.pop();
                char o = op.top();
                op.pop();
                string t = o + v1 + v2;
                st.push(t);

                op.push(ch);
            }

            if (ch == '*' || ch == '/')
            {
                if (op.top() == '*' || op.top() == '/')
                {
                    string v2 = st.top();
                    st.pop();
                    string v1 = st.top();
                    st.pop();
                    char o = op.top();
                    op.pop();
                    string t = o + v1 + v2;
                    st.push(t);

                    op.push(ch);
                }
                else
                    op.push(ch);
            }
        }
    }

    while (st.size() > 1)
    {
        string v2 = st.top();
        st.pop();
        string v1 = st.top();
        st.pop();
        char o = op.top();
        op.pop();
        string t = o + v1 + v2;
        st.push(t);
    }

    string res = st.top();
    cout << res << endl;

    return 0;
}
