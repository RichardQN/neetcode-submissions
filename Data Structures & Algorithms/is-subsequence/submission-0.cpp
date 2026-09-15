class Solution {
public:
    bool isSubsequence(string s, string t) {
        unordered_set<char> seen;
        int spointer = 0;
        int tpointer = 0;

        while (tpointer < t.size()){
            if (seen.contains(t[tpointer])){
                spointer - 1;
            }
            if (t[tpointer] == s[spointer]){
                spointer++;
                seen.insert(s[spointer]);
            }
            tpointer++;

        }
        if (spointer == (s.size())){
            return true;
        }
        return false;
    }
};