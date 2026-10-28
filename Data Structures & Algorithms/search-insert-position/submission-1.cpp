class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0 , r = nums.size() - 1;
        int save = nums.size();
        while (l <= r){
            int mid = l + (r-l)/2;
            
            if (nums[mid] == target){
                return mid;
            } else if (nums[mid] > target){
                save= mid;
                r = mid -1;
            } else {
                l = mid + 1;
            }
        }
        return save;
        
    }
};