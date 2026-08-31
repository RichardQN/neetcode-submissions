class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++){
            if (nums[i] > 0){break;}
            if ((i > 0) && nums[i] == nums[i-1]){continue;}

            int j = i + 1, r = nums.size() - 1;
            while (j < r){
                int sum = nums[i] + nums[j] + nums[r];
                if (sum > 0){
                    r--;
                } else if (sum < 0){
                    j++;
                } else {
                    res.push_back({nums[i], nums[j], nums[r]});
                    j++;
                    r--;
                    while ((j < r) && nums[j] == nums[j-1]){
                        j++;
                    }
                }
            }
            
        }
        return res;
    }
};
