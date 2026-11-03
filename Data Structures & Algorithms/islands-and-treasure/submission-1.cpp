class Solution {
public:
    int ROWS, COLS;
    int INF = INT_MAX;
    vector<vector<int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<tuple<int, int, int>> q;
        ROWS = grid.size(), COLS = grid[0].size();
        vector<vector<bool>> visited(ROWS, vector<bool>(COLS, false));
        for (int r = 0; r < ROWS; r++){
            for (int c = 0; c < COLS; c++){
                if (grid[r][c] == 0){
                    q.push(make_tuple(r, c, 0));
                    visited[r][c] = true;
                }
            }
        }
        bfs(q, grid, visited);

    }

    void bfs(queue<tuple<int, int, int>>& q, vector<vector<int>>& grid, vector<vector<bool>>& visited){
        while (!q.empty()){
            int len = q.size();
            for (int i = 0; i < len; i++){
                auto [row, col, dist] = q.front();
                q.pop();

                for (int i = 0; i < 4; i++){
                    int nr = row + dir[i][0];
                    int nc = col + dir[i][1];

                    if ((0 <= nr) && (nr < ROWS) && (0 <= nc) && (nc < COLS) && (grid[nr][nc] != -1) && (!visited[nr][nc])){
                        visited[nr][nc] = true;
                        grid[nr][nc] = dist + 1;
                        q.push(make_tuple(nr, nc, dist + 1));
                    } 
                }
            }
            
        }

    }
};
