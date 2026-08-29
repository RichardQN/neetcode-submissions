class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numset(nums.begin(), nums.end());
        int res = 1;
        if (nums.empty()){
            return 0;
        }
        for (int n : numset){
            if (!numset.contains(n-1)){
                int length = 1;
                while (numset.contains(n+length)){
                    length++;
                    res = max(res, length);
                }
            }
        }
        return res;


    }
};
