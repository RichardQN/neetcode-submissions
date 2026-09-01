class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> sa;
        unordered_map<char, int> ta;

        for (char c : s){
            sa[c]++;
        }
        for (char c : t){
            ta[c]++;
        }

        if (sa == ta){
            return true;
        } else {
            return false;
        }
    }
};
