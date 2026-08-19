class Solution {
public:
    bool canPlace(int n, vector<string>& board, int row, int col){
        // check col
        for(int i=0; i<n; i++){
            if(board[i][col] == 'Q')
                return false;
        }

        //left diagonal
        for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--){
            if(board[i][j] == 'Q')
                return false;
        }

        //right diagonal
        for(int i=row-1, j=col+1; i>=0 && j<n; i--, j++){
            if(board[i][j] == 'Q')
                return false;
        }

        return true;
    }

    void solve(int row, int n, vector<vector<string>>& ans, vector<string>& board){
        // all queens placed in board
        if(row == n){
            ans.push_back(board);
            return;
        }

        // in each row, add a queen
        for(int col=0; col<n; col++){
            if(canPlace(n, board, row, col)){
                board[row][col] = 'Q';
                solve(row+1, n, ans, board);

                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n,'.'));

        solve(0, n, ans, board);
        return ans;
    }
};
