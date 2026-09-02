class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> m = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for (char c : s){
            if (m.contains(c)){
                if (!st.empty() && st.top() == m[c]){
                    st.pop();
                } else {
                    return false;
                }
            } else {
                st.push(c);
            }

        }
        return st.empty();
    }
};
