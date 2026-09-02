class Solution {
public:

    bool skipLogic(const string& s, int l, int r){
        while (l < r){
            if (s[l] != s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while ((l < r)){
            if (s[l] != s[r]){
                return skipLogic(s, l + 1, r) || skipLogic(s, l, r - 1);
            } 
            l++;
            r--;

        }
        return true;
    }
};