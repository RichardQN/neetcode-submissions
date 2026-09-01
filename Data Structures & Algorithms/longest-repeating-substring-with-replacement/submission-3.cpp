class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<int, int> m;
        int l = 0, r = 0, maxf = 0;
        int res = 0;
        while (r < s.size()){
            m[s[r]]++;
            maxf = max(maxf, m[s[r]]);

            if ((r-l+1) - maxf > k){
                m[s[l]]--;
                l++;
            }
            res = max(r-l+1, res);
            r++;
            
        }
        return res;
    }
};
