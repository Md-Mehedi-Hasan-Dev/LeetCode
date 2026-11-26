class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char p : s)
        {
            if(p == '(' || p == '{' || p == '[')
                st.push(p);
            else if(!st.empty())
            {
                if((st.top() == '(' && p == ')') || (st.top() == '{' && p == '}') || (st.top() == '[' && p == ']'))
                    st.pop();
                else
                    st.push(p);
            }
            else
                st.push(p);
        }
        return st.empty();
    }
};