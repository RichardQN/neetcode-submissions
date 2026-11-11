class Solution {
public:
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int ROWS, COLS;
    int numIslands(vector<vector<char>>& grid) {
        ROWS = grid.size(), COLS = grid[0].size();
        int count = 0;
        for (int r = 0; r < ROWS; r++){
            for (int c = 0; c < COLS; c++){
                if (grid[r][c] == '1'){
                    bfs(r, c, grid);
                    count++;
                }
            }
        }
        return count;
    }

    void bfs(int r, int c, vector<vector<char>>& grid){
        queue<pair<int, int>> q;
        q.push({r, c});
        grid[r][c] = '0';
        while (!q.empty()){
            auto node = q.front();
            q.pop();
            int row = node.first, col = node.second;

            for (int i = 0; i < 4; i++){
                int nr = row + dir[i][0];
                int nc = col + dir[i][1];

                if (((nr >= 0) && (nr < ROWS) && (nc >= 0) && (nc < COLS) && (grid[nr][nc] == '1'))){
                    q.push({nr, nc});
                    grid[nr][nc] = '0';
                }
            }

        }

    }
};
