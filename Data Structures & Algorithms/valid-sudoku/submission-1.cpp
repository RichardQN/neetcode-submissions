class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++){
            if (!(isValidRow(board, i) && isValidCol(board, i) && isValidBlock(board, i))){return false;}
        } 
        return true;
    }

    bool isValidRow(vector<vector<char>>& board, int row_num){
        unordered_set<char> row;
        for (int i = 0; i < 9; i++){
            if (board[row_num][i] == '.'){continue;}
            if (row.contains(board[row_num][i])){return false;}
            row.insert(board[row_num][i]);
        }
        return true;
    }

    bool isValidCol(vector<vector<char>>& board, int col_num){
        unordered_set<char> col;
        for (int i = 0; i < 9; i++){
            if (board[i][col_num] == '.'){continue;}
            if(col.contains(board[i][col_num])){return false;}
            col.insert(board[i][col_num]);
        }
        return true;
    }

    bool isValidBlock(vector<vector<char>>& board, int block_num){
        unordered_set<char> block;
        int start_row = (block_num / 3) * 3;
        int start_col = (block_num % 3) * 3;
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                char c = board[start_row + i][start_col + j];
                if (c == '.') { continue; }
                if (block.contains(c)) { return false; }
                block.insert(c);
            }
        }
        return true;
    }
};
