class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams;
        vector<vector<string>> res;
        for (string s : strs){
            vector<int> count(26);
            string key = "";
            for (char c : s){
                count[c - 'a']++;
            }
            for (int n : count){
                key += to_string(n) + ',';
            }
            anagrams[key].push_back(s);
        }
        for (auto& pair : anagrams){
            res.push_back(pair.second);
        }
        return res;
    }
};
