class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0;
        int res = INT_MAX;
        int runningSum = 0;
        for (int r = 0; r < nums.size(); r++){
            runningSum += nums[r];
            while (runningSum >= target){
                res = min(res, r-l+1);
                runningSum -= nums[l];
                l++;
            }
        }
        if (l == 0){
            return 0;
        }
        return res;
    }
};