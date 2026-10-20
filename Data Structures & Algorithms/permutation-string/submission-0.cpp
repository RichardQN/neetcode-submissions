class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        /* make a window, make sure it only stays in the size of s1, window should count frequency */
        vector<int> windowPerm(26, 0);
        vector<int> slidingWindow(26, 0);

        if (s2.size() < s1.size()){
            return false;
        }

        for (char c : s1){
            windowPerm[c -'a']++;
        }

        int l = 0, r = 0, len = s1.size();

        for (int i = 0; i < len; i++){
            slidingWindow[s2[i] - 'a']++;
        }

        if (slidingWindow == windowPerm){
            return true;
        }

        r = len;
        slidingWindow[s2[l] - 'a']--;
        l++;
        
        while (r < s2.size()){
            slidingWindow[s2[r] - 'a']++;
            if (slidingWindow == windowPerm){
                return true;
            }
            r++;
            slidingWindow[s2[l] - 'a']--;
            l++;

        }
        return false;


    }
};
