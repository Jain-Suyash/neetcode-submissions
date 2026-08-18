class Solution {
   public:
    bool isValid(string s) {
        stack<char> st;

        for (auto c : s) {
            if (c == '(' || c == '[' || c == '{')
                st.push(c);

            else {
                char tp = st.empty() ? '-' : st.top();
                if ((tp == '(' && c == ')') || (tp == '{' && c == '}') || (tp == '[' && c == ']'))
                    st.pop();
                else
                    return false;
            }
        }

        return st.empty();
    }
};
