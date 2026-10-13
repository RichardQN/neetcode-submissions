class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> st;
        unordered_map<char, int> tt;

        for (char c : s){
            st[c]++;
        }
        for (char c : t){
            tt[c]++;
        }

        if (tt == st){
            return true;
        }
        return false;
    }
};
