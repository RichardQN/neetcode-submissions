class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++){
            m[nums[i]]++;

        }
        while (k != 0){
            int maxEl = 0;
            int maxFreq = 0;
            for (auto& pair : m){
                if (pair.second > maxFreq){
                    maxFreq = pair.second;
                    maxEl = pair.first;
                }
            }
            m.erase(maxEl);
            res.push_back(maxEl);
            k--;
        }
        return res;




            
        
    }
};
