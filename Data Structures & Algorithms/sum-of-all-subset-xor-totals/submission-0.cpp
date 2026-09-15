class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        return dfs(0, 0, nums);
    }

    int dfs(int index, int total, vector<int>& nums){
        if (index == nums.size()){
            return total;
        }
        return dfs(index+1, total^nums[index], nums) + dfs(index+1, total, nums);


    }
};