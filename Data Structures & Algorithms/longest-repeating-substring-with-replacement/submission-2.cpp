class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<int, int> goat;
        int l = 0;
        int res = 0;
        int maxf = 0;
        for (int r = 0; r < s.size(); r++){
            goat[s[r]]++;
            maxf = max(maxf, goat[s[r]]);

            while ((r-l+1) - maxf > k){
                goat[s[l]]--;
                l++;
            }
            res = max(res, r-l+1);
        }   
        return res;
    }
};
