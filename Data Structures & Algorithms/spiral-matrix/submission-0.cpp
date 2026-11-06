class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        int r = 0, c = 0;
        vector<int> res;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        /*
        row true = goes forward row count
        row false = goes backward row count
        col = true = goes froward col count
        col = false = goes backwrard col count
        master true = row goes now
        master false = col goes now
        */

        bool row = true, col = true, master = false;
        while (res.size() != (rows * cols)){
            if (master){
                if (row){
                    while (r < rows && visited[r][c] != true){
                        res.push_back(matrix[r][c]);
                        visited[r][c] = true;
                        r++;
                    }
                    row = false;
                    r--;
                    c--;
                } else {
                    while (r >= 0 && visited[r][c] != true){
                        res.push_back(matrix[r][c]);
                        visited[r][c] = true;
                        r--;
                    }
                    row = true;
                    r++;
                    c++;
                    
                }
            } else {
                if (col){
                    while (c < cols && visited[r][c] != true){
                        res.push_back(matrix[r][c]);
                        visited[r][c] = true;
                        c++;
                    }
                    col = false;
                    c--;
                    r++;
                } else {
                    while (c >= 0 && visited[r][c] != true){
                        res.push_back(matrix[r][c]);
                        visited[r][c] = true;
                        c--;
                    }
                    col = true;
                    c++;
                    r--;
                }
            }
            master = !master;
            

        }
        return res;

    }
};
