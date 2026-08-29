class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()){
            return false;
        }
        unordered_map<char, int> ms;
        unordered_map<char, int> mt;
        for (char c : s){
            ms[c]++;
        }
        for (char c : t){
            mt[c]++;
        }
        if (ms == mt){
            return true;
        } else {
            return false;
        }
    }

};
