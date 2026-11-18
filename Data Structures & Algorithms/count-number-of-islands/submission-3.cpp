class Solution {
public:
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int ROWS, COLS;
    int numIslands(vector<vector<char>>& grid) {
        ROWS = grid.size(), COLS = grid[0].size();
        int res = 0;
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (grid[r][c] == '1') {
                    bfs(grid, r, c);
                    res++;
                }
            }
        }
        return res;
    }

    void bfs(vector<vector<char>>& grid, int r, int c) {
        queue<pair<int,int>> q;
        q.push({r, c});
        grid[r][c] = '0';

        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = row + dir[i][0];
                int nc = col + dir[i][1];

                if ((nr >= 0) && (nr < ROWS) && (nc >= 0) && (nc < COLS) && grid[nr][nc] == '1') {
                    q.push({nr, nc});
                    grid[nr][nc] = '0';
                }
            }
        }
    }
};
