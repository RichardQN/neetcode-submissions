class Solution {
public:
    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    int ROWS, COLS;
    int freshCount = 0, res = 0;
    int orangesRotting(vector<vector<int>>& grid) {
        ROWS = grid.size(), COLS = grid[0].size();
        queue<pair<int ,int>> q;
        for (int r = 0; r < ROWS; r++){
            for (int c = 0; c < COLS; c++){
                if (grid[r][c] == 1){
                    freshCount++;
                } else if (grid[r][c] == 2){
                    q.push({r, c});
                }
            }
        }
        bfs(q, grid);
        if (freshCount == 0){
            return res;
        } else {
            return -1;
        }
    }

    void bfs(queue<pair<int, int>>& q, vector<vector<int>>& grid){
        while (!q.empty()){
            int len = q.size();
            for (int i = 0; i < len; i++){
                auto node = q.front();
                int row = node.first, col = node.second;
                q.pop();

                for (int j = 0; j < 4; j++){
                    int nr = row + dir[j][0];
                    int nc = col + dir[j][1];

                    if ((nr >= 0) && (nr < ROWS) && (nc >= 0) && (nc < COLS) && (grid[nr][nc] == 1)){
                        grid[nr][nc] = 2;
                        freshCount--;
                        q.push({nr, nc});
                    }
                }


            }
            if (!q.empty()){
                res++;
            }
            
        }
    }
};
