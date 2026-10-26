class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k =0;
        for (int n : nums){
            if (n != val){
                k++;
            }
        }
        erase(nums, val);
        return k;
        
    }
};