class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        for (int i = 0; i < n+1; i++) {
            int x = i;
            int count = 0;
            while (x) {
                x &= (x -1);
                count++;
            }
            res.push_back(count);
        }
        return res;
    }
};
