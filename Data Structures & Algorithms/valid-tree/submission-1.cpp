class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() > (n-1)){
            return false;
        }
        unordered_map<int, vector<int>> adjList;

        for (const auto& edge :edges){
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        unordered_set<int> visited;

        if (!dfs(0, -1, adjList, visited)){
            return false;
        }

        return visited.size() == n;

        
    }

    bool dfs(int node, int parent, unordered_map<int, vector<int>>& adjList, unordered_set<int>& visited){
        if (visited.contains(node)){
            return false;
        }

        visited.insert(node);
        for (int nei : adjList[node]){
            if (nei == parent){
                continue;
            }

            if (!dfs(nei, node, adjList, visited)){
                return false;
            }
        }
        return true;

    }


};
