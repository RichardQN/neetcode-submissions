class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        vector<vector<string>> res;

        for (string s : strs){
            vector<int> count(26);
            for (char c : s){
                count[c- 'a']++;
            }
            string key = "";
            for (int n : count){
                key += to_string(n) + ',';
            }
            m[key].push_back(s);
        }

        for (auto& pair : m){
            res.push_back(pair.second);
        }
        return res;
    }
};
