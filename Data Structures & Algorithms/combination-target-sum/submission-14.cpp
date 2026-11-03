class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        dfs(0, 0, nums, target, {});
        return res;
    }

    void dfs(int i, int sum, vector<int>& nums, int target, vector<int> path){
        if (sum == target){
            res.push_back(path);
            return;
        }

        if (sum > target || i >= nums.size()){
            return;
        }

        if (sum + nums[i] > target){return;}

        path.push_back(nums[i]);
        dfs(i, sum + nums[i], nums, target, path);
        path.pop_back();
        dfs(i+1, sum, nums, target, path);

        


    }
};
