class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rowSet(9);
        vector<unordered_set<char>> colSet(9);
        vector<unordered_set<char>> boxSet(9);

        for(int row=0; row<9; row++){
            for(int col=0; col<9; col++){
                if(board[row][col] == '.') continue;

                char dig = board[row][col];

                int boxIdx = (row/3)*3 + col/3;      //boxes 0-8 idx

                if(rowSet[row].find(dig) != rowSet[row].end()) return false;
                if(colSet[col].find(dig) != colSet[col].end()) return false;
                if(boxSet[boxIdx].find(dig) != boxSet[boxIdx].end()) return false;

                rowSet[row].insert(dig);
                colSet[col].insert(dig);
                boxSet[boxIdx].insert(dig);
            }
        }
        return true;
    }
};
