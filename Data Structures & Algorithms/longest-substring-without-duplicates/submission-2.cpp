class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> window;
        int l = 0, length = 0;
        for (int r = 0; r < s.size(); r++){
            while (window.contains(s[r])){
                window.erase(s[l]);
                l++;
            } 
            window.insert(s[r]);
            length = max(length, r - l + 1);
        }
        return length;
    }
};
