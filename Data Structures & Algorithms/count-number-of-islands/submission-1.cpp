class Solution {
public:
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size(), col = grid[0].size(), islands = 0;

        if (grid.empty()){
            return 0;
        }

        for (int r = 0; r < rows; r++){
            for (int c = 0; c < col; c++){
                if (grid[r][c] == '1'){
                    bfs(grid, r, c);
                    islands++;
                }
            }
        }
        return islands;
    }

    void bfs(vector<vector<char>>& grid, int row, int col){
        queue<pair<int, int>> q;
        grid[row][col] = '0';
        q.push({row, col});

        while (!q.empty()){
            auto node = q.front();
            q.pop();
            int r = node.first, c = node.second;

            for (int i = 0; i < 4; i++){
                int nr = r + directions[i][1];
                int nc = c + directions[i][0];
                if ((nr < grid.size()) && (nc < grid[0].size()) && (grid[nr][nc] == '1')){
                    q.push({nr, nc});
                    grid[nr][nc] = '0';
                }
            }
        }
    }
};
