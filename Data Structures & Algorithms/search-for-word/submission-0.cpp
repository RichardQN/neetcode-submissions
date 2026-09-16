class Solution {
public:
    int rows, cols;
    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size(), cols = board[0].size();

        for (int r = 0; r < rows; r++){
            for (int c = 0; c < cols; c++){
                if (dfs(0, word, r, c, board)){return true;}
            }
        }
        return false;
    }

    bool dfs(int i, string word, int r, int c, vector<vector<char>>& board){
        if (i == word.size()){
            return true;
        }

        if (!((r >= 0) && (c >= 0) && (r < rows) && (c < cols) && (board[r][c] == word[i]) && (board[r][c]) != '#')){
            return false;
        }

        board[r][c] = '#';
        bool res = dfs(i+1, word, r+1, c, board) ||
                   dfs(i+1, word, r-1, c, board) ||
                   dfs(i+1, word, r, c+1, board) ||
                   dfs(i+1, word, r, c-1, board);
        
        board[r][c] = word[i];
        return res;
    }
};
