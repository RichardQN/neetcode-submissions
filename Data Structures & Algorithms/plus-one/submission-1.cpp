class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int r = digits.size() - 1;
        if (digits[r] == 9){
            while (r >= 0 && digits[r] == 9){
                digits[r] = 0;
                r--;
            }
            if (r < 0) {
                digits.insert(digits.begin(), 1);
            } else {
                digits[r]++;
            }
        } else {
            digits[r]++;
        }
        return digits;

    }
};
