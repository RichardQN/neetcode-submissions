class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l = 0, r = 0, count = 0;
        for (int r = 0; r < nums.size(); r++){
            if (nums[r] != 0){
                swap(nums[l], nums[r]);
                l++;
                count++;
            }

        }
        int remain = count;
        while (count < nums.size()){
            nums[count] = 0;
            count++;
        }
    }
};