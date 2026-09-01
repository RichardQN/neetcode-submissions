class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> win;
        int l = 0;
        int length = 0;
        for (int r = 0; r < s.size(); r++){
            while (win.contains(s[r])){
                win.erase(s[l]);
                l++;
            }
            win.insert(s[r]);
            length = max(length, r-l+1);
        }
        return length;
        
    }
};
