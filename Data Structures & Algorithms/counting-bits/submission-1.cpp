class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        for (int i = 0; i < n+1; i++){
            int count = 0;
            for (int j = 0; j < 32; j++){
                if (i & (1 << j)){
                    count++;
                }
            }
            res.push_back(count);
        }
        return res;
    }
};
