class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        for (int i = 0; i <= n; i++){
            int j = i, c = 0;
            while (j){
                j &= (j-1);
                c++;
            }
            res.push_back(c);
        }
        return res;
    }
};
