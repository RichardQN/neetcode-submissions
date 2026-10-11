class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        dfs(0, {}, 0, nums, target);
        return res;
    }

    void dfs(int index, vector<int> current, int total, vector<int>& nums, int target){
        if (total == target){
            res.push_back(current);
            return;
        }

        for (int j = index; j < nums.size(); j++){
            if (total > target){
                return;
            } else {
                current.push_back(nums[j]);
                dfs(j, current, total + nums[j], nums, target);
                current.pop_back();
            }
        }
    }
};
