class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> window;
        int l = 0;
        int maxf = 0, len = 0;
        for (int r = 0; r < s.size(); r++){
            window[s[r]]++;
            maxf = max(window[s[r]], maxf);

            while ((r-l+1) - maxf > k){
                window[s[l]]--;
                l++;
            }
            len = max(len, r-l+1);
           
        }
        return len;
        
    }
};
