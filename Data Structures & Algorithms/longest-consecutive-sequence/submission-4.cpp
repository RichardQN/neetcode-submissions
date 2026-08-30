class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest = 1;
        unordered_set<int> s(nums.begin(), nums.end());
        if (nums.empty()){
            return 0;
        }
        for (int n : nums){
            if (!s.contains(n-1)){
                int length = 1;
                while (s.contains(n+length)){
                    length++;
                }
                longest = max(longest, length);
            }
        }
        return longest;
    }
};
