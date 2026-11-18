class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.size() < p.size()) {
            return {};
        }
        
        vector<int> c(26, 0);
        vector<int> res;
        vector<int> count(26, 0);
        for (char c : p) {
            count[c - 'a']++;
        }
        
        int i = 0;
        while (i < p.size()) {
            c[s[i] - 'a']++;
            i++;
        }
        if (c == count) {
            res.push_back(0);
        }
        
        int l = 0, r = i;
        while (r < s.size()) {
            c[s[r] - 'a']++;     
            c[s[l] - 'a']--;     
            r++;
            l++;
            if (c == count) res.push_back(l); 
        }

        return res;
    }
};
