class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int l = 0;
        for (int n : nums){
            if (!(s.contains(n-1))){
                int length = 1;
                while (s.contains(n+length)){
                    length++;
                }
                l = max(length, l);
            }
        }
        return l;
    }
};
