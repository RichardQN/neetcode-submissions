class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> freq(nums.size()+1);
        unordered_map<int, int> count;
        vector<int> res;
        
        for (int n : nums){
            count[n]++;
        }

        for (auto& node : count){
            freq[node.second].push_back(node.first);
        }

        for (int i = freq.size()-1; i >= 0; i--){
            for (int n : freq[i]){
                res.push_back(n);
            }
            if (res.size() == k){
                return res;
            }
        }
        return res;
    }
};
