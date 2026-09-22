class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mt;
        unordered_map<char, int> ms;

        for (char c : s){
            ms[c]++;
        }
        for (char c: t){
            mt[c]++;
        }

        if (ms == mt){
            return true;
        }
        return false;
    }
};
