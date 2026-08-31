class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0, l = 0;
        unordered_set<char> m;

        for (int r = 0; r < s.size(); r++){
            while (m.contains(s[r])){
                m.erase(s[l]);
                l++;
            }
            m.insert(s[r]);
            res = max(res, r-l+1);
        }
        return res;
    }
};
