class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> cs;
        unordered_map<char, int> ct;

        for (char c : s){
            cs[c]++;
        }
        for (char c : t){
            ct[c]++;
        }

        if (ct == cs){
            return true;
        } else {
            return false;
        }
    }
};
