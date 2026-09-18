class Solution {
public:
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<int>> res;
    int ROWS, COLS;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        ROWS = heights.size(), COLS = heights[0].size();

        for (int r = 0; r < ROWS; r++){
            for (int c = 0; c < COLS; c++){
                if (bfs(r, c, heights)){
                    res.push_back({r, c});
                }
            }
        }
        return res;
    }

    bool bfs(int r, int c, vector<vector<int>>& heights){
        vector<vector<bool>> visited(ROWS, vector<bool>(COLS, false));
        queue<pair<int, int>> q;
        q.push({r, c});
        visited[r][c] = true;
        bool atlantic = false;
        bool pacific = false;

        while (!q.empty()){
            auto node = q.front();
            q.pop();
            int row = node.first, col = node.second;

            for (int i = 0; i < 4; i++){
                int nr = row + dir[i][0];
                int nc = col + dir[i][1];

                if ((nr < 0) || (nc < 0)){
                    pacific = true;
                }
                if ((nr >= ROWS) || (nc >= COLS)){
                    atlantic = true;
                }

                if (nr < 0 || nr >= ROWS || nc <0 || nc >= COLS){continue;}
                if (visited[nr][nc]){continue;}
                if (heights[row][col] >= heights[nr][nc]){
                    q.push({nr, nc});
                    visited[nr][nc] = true;
                }
            }
        }
        return atlantic && pacific;
        
    }
};
