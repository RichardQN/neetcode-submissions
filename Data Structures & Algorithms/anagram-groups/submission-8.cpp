class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> anagrams;

        for (string s : strs){
            vector<int> count(26, 0);
            for (char c : s){
                count[c - 'a']++;
            }

            string key = "";
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
