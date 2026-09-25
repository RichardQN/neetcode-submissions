class Solution {
public:
    unordered_map<int, vector<int>> cycle;
    unordered_set<int> visiting;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (int i = 0; i < numCourses; i++){
            cycle[i] = {};
        }

        for (const auto& p : prerequisites){
            cycle[p[0]].push_back(p[1]);
        }

        for (int c = 0; c < numCourses; c++){
            if (!dfs(c)){
                return false;
            }
        }
        return true;
    }
    bool dfs(int ch){
        if (visiting.contains(ch)){
            return false;
        }

        if (cycle[ch].empty()){
            return true;
        }

        visiting.insert(ch);
        for (int pre : cycle[ch]){
            if (!dfs(pre)){
                return false;
            }
        }
        visiting.erase(ch);
        cycle[ch].clear();
        return true;
    }

};
