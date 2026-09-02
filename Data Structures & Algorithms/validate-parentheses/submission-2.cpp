class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> m = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        stack<char> st;

        for (char c : s){
            if (m.contains(c)){
                if ((!st.empty()) && st.top() == m[c]){
                    st.pop();
                } else{
                    return false;
                }
            } else{
                st.push(c);
            }
        }
        return st.empty();

    }
};
