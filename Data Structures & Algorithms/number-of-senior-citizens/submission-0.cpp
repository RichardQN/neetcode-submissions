class Solution {
public:
    int countSeniors(vector<string>& details) {
        int first = 11, second = 12;
        int res = 0;
        for (string s : details) {
            int digit1 = (s[first] - '0') * 10;
            int digit2 = (s[second] - '0');
            int sum = digit1 + digit2;
            if (sum > 60) {
                res++;
            }
        }
        return res;
    }
};