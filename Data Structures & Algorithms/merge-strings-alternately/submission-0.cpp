class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res = "";
        int l = 0, r = 0;
        bool one = false, two = false;
        while (l < word1.size() && r < word2.size()){
            res += word1[l];
            if (l + 1 >= word1.size()){one = true;}
            l++;
            res += word2[r];
            if (r + 1 >= word2.size()){two = true;}
            r++;
        }
        if (one && two){return res;}
        string rest = (one) ? word2.substr(r) : word1.substr(l);
        res.append(rest);
        return res;

        
    }
};