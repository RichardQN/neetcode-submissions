class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest = 0;
        unordered_set<int> s(nums.begin(), nums.end());
        for (int n : nums){
            if (!(s.contains(n-1))){
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
