class Solution {
public:
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image.empty()){return image;}
        return bfs(image, sr, sc, color);
    }

    vector<vector<int>> bfs(vector<vector<int>>& image, int sr, int sc, int color){
        int rows = image.size(), cols = image[0].size();
        queue<pair<int,int>> q;
        q.push({sr, sc});
        int original = image[sr][sc];
        image[sr][sc] = color;

        while (!q.empty()){
            auto node = q.front();
            q.pop();
            int r = node.first, c = node.second;

            for (int i = 0; i < 4; i++){
                int nr = r + dir[i][0];
                int nc = c + dir[i][1];

                if ((nr >= 0) && (nc >= 0) && (nr < rows) && (nc < cols) && (image[nr][nc] == original) && (image[nr][nc] != color)){
                    q.push({nr, nc});
                    image[nr][nc] = color;
                }

            }
        }
        return image;
    }
};