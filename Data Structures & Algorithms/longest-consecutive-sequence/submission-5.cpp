class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> nset(nums.begin(), nums.end());
        int res = 0;
        if (nset.empty()){
            return 0;
        }
        for (int n : nums){
            if (!nset.contains(n-1)){
                int length = 1;
                while (nset.contains(n+length)){
                    length++;
                }
                res = max(res, length);
            }
        }
        return res;
    }
};
