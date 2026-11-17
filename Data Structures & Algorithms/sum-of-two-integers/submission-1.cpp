class Solution {
public:
    int getSum(int a, int b) {
        int res = 0, carry = 0;
        while (b) {
            int carry = (a & b) << 1;
            a ^= b;
            b = carry;
        }
        return a;
    }
};
