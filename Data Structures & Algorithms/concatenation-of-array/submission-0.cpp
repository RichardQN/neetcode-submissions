class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int l = 0;
        vector<int> res = nums;
        while (l < nums.size()){
            res.push_back(nums[l]);
            l++;
        }
        return res;
    }
};