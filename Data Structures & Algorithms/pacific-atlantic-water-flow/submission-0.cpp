class Solution {
public:
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        int rows = heights.size(), cols = heights[0].size();

        for (int r = 0; r < rows; r++){
            for (int c = 0; c < cols; c++){
                if (bfs(heights, r, c)){
                    res.push_back({r, c});
                } 
            }
        }
        return res;
    }

    bool bfs(vector<vector<int>>& heights, int r, int c){
        /* pacific would be -1 in col or row, atlantic would be + 1 in col or row*/
        int rows = heights.size(), cols = heights[0].size();
        queue<pair<int, int>> q;
        q.push({r, c});
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        visited[r][c] = true;
        bool atlantic = false, pacific = false;

        while (!q.empty()){
            auto node = q.front();
            q.pop();
            int row = node.first, col = node.second;
            for (int i = 0; i < 4; i++){
                int nr = row + dir[i][0];
                int nc = col + dir[i][1];
                if (nr < 0 || nc < 0){
                    pacific = true;
                } 
                if (nr >= rows || nc >= cols){
                    atlantic = true;
                }
                if (nr < 0 || nr >= rows || nc <0 || nc >= cols){continue;}
                if (visited[nr][nc]){continue;}
                if (heights[row][col] >= heights[nr][nc]){
                    q.push({nr, nc});
                    visited[nr][nc] = true;
                }

                
            }
            if (atlantic && pacific){return true;}
            
        }
        return atlantic && pacific;
    }
};
