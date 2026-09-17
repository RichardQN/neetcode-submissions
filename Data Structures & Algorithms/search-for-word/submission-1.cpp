class Solution {
public:
    int rows, cols;
    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();
        if (board.empty()){
            return false;
        }
        for (int r = 0; r < rows; r++){
            for (int c = 0; c < cols; c++){
                if (dfs(0, r, c, board, word)){
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(int i, int r, int c, vector<vector<char>>& board, string word){
        if (i == word.size()){
            return true;
        }
        if (!((r >= 0) && (c >= 0) && (r < rows) && (c < cols) && (board[r][c] != '#') && board[r][c] == word[i])){
            return false;
        }
        board[r][c] = '#';
        bool res = dfs(i+1, r + 1, c, board, word) ||
                   dfs(i+1, r - 1, c, board, word) ||
                   dfs(i+1, r, c+1, board, word) ||
                   dfs(i+1, r,c-1, board, word);
        
        board[r][c] = word[i];
        return res;


    }
};
