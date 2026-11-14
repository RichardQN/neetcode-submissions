class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        for (int i = 0; i <= n; i++){
            int count = 0, j = i;
            while (j) {
                j &= (j - 1);
                count++;
            }
            res.push_back(count);
        }
        return res;
    }
};
