class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> freq;
        vector<vector<int>> heatmap(nums.size() + 1);

        for (int n : nums){
            freq[n]++;
        }

        for (const auto& pair : freq){
            heatmap[pair.second].push_back(pair.first);
        }

        for (int i = heatmap.size() - 1; i >= 0; i--){
            for (int n : heatmap[i]){
                res.push_back(n);
            }
            if (res.size() == k){
                return res;
            }
        }
        return res;
    }
};
