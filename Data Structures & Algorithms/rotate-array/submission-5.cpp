class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int r = nums.size() - 1;
        while (k > 0){
            nums.insert(nums.begin(), nums[r]);
            nums.pop_back();
            k--;
        }




    }
};