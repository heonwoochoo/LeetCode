class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (auto c : s)
        {
            if (c == '(' || c == '{' || c == '[')
            {
                st.push(c);
            }
            else
            {
                if (st.empty()) return false;
                char t = st.top();
                if (c == ')')
                {
                    if (t == '(') st.pop();
                    else return false;
                }
                else if (c == '}')
                {
                    if (t == '{') st.pop();
                    else return false;
                }
                else
                {
                    if (t == '[') st.pop();
                    else return false;
                }
            }
        }
        if (st.empty()) return true;
        return false;
    }
};