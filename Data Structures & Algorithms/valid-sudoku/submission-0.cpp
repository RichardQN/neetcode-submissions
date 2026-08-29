class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rows[9];
        unordered_set<char> col[9];
        unordered_set<char> box[9];

        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                char c = board[i][j];

                if (c == '.') {continue;}

                int boxIndex = (i/3)*3 + (j/3);

                if (!rows[i].insert(c).second) {return false;}
                if (!col[j].insert(c).second){return false;}
                if (!box[boxIndex].insert(c).second) {return false;}
            }
        }
        return true;
    }
};
