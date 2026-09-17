class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> curr;
        dfs(1, curr, n, k);
        return res;
    }

    void dfs(int len, vector<int>& curr, int n, int k){
        if (len > n){ 
            if (curr.size() == k){
                res.push_back(curr);
                
            }
            return;
        }
        

        curr.push_back(len);
        dfs(len+1, curr, n, k);
        curr.pop_back();
        dfs(len + 1, curr, n, k);


    }
};