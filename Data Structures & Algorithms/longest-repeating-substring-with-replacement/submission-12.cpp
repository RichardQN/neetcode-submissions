class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> window;
        int l = 0, maxFreq = 0, len = 0;
        for (int r = 0; r < s.size(); r++){
            window[s[r]]++;
            maxFreq = max(window[s[r]], maxFreq);

            while ((r-l+1) - maxFreq > k){
                window[s[l]]--;
                l++;
            }
            len = max(len, r-l+1);

        }
        return len;
    }
};
