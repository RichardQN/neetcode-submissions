class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> window;
        int l = 0, r = 0, length = 0;
        while (r < s.size()){
            while (window.contains(s[r])){
                window.erase(s[l]);
                l++;
            }
            window.insert(s[r]);
            length = max(length, r-l+1);
            r++;
        }
        return length;
    }
};
