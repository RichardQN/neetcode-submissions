class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> lol = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        stack<char> st;

        for (char c : s){
            if (lol.contains(c)){
                if ((!st.empty()) && st.top() == lol[c]){
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
