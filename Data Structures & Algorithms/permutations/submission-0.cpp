class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> pick(nums.size(), false);
        dfs(nums, {}, pick);
        return res;
    }

    void dfs(vector<int>& nums, vector<int> perm, vector<bool>& pick) {
        if (perm.size() == nums.size()) {
            res.push_back(perm);
            return;
        }

        for (int i = 0; i < nums.size(); i++){
            if (!pick[i]) {
                perm.push_back(nums[i]);
                pick[i] = true;
                dfs(nums, perm, pick);
                perm.pop_back();
                pick[i]= false;
            }
        }

        
    }
};
