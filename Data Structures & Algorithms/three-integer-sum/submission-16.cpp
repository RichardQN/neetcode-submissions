class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] > 0){break;}
            if ((i>0) && nums[i] == nums[i-1]){continue;}

            int l = i+1, r = nums.size() -1;
            while (l < r){
                int sum = nums[l] + nums[r] + nums[i];
                if (sum == 0){
                    res.push_back({nums[l], nums[r], nums[i]});
                    l++;
                    r--;
                    while ((l<=r) && nums[l] == nums[l-1]){
                    l++;
                    }
                } else if (sum > 0){
                    r--;
                } else{
                    l++;
                }
            
            }
        }
        return res;
    }
};
