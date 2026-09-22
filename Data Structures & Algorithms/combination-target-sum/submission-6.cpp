class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        dfs(0, {}, 0, nums, target);
        return res;
    }

    void dfs(int i, vector<int> curr, int total, vector<int>& nums, int target){
        if (total == target){
            res.push_back(curr);
            return;
        }

        for (int j = i; j < nums.size(); j++){
            if (total > target){
                return;
            }
            curr.push_back(nums[j]);
            dfs(j, curr, nums[j] + total, nums, target);
            curr.pop_back();
        }
        
    }
};
