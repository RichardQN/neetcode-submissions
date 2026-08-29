class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> m;
        for (int n : nums){
            if (m.contains(n)){
                return true;
            }
            m.insert(n);
        }
        return false;
    }
};