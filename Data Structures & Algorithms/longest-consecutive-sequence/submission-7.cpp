class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        if (s.empty()){
            return 0;
        }
        int res = 0;
        for (int n : nums){
            
            if (!s.contains(n-1)){
                int length = 1;
                while (s.contains(n+length)){
                    length++;
                }
                res = max(res, length);
            }

        }
        return res;
    }
};
