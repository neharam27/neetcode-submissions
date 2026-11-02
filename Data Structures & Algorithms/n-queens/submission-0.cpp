class Solution {

    bool isSafe(vector<vector<int>>& board, int row, int col, int n) {

        for (int i = 0; i < row; i++) {
            if (board[i][col] == 1)
                return false;
        }

        for (int i = row - 1, j = col - 1;
             i >= 0 && j >= 0; i--, j--) {

            if (board[i][j] == 1)
                return false;
        }

        for (int i = row - 1, j = col + 1;
             i >= 0 && j < n; i--, j++) {

            if (board[i][j] == 1)
                return false;
        }

        return true;
    }

    void solveNQueens(vector<vector<int>>& board, int row, int n,
                      vector<vector<string>>& result) {

        if (row == n) {

            vector<string> solution;

            for (int i = 0; i < n; i++) {

                string s = "";

                for (int j = 0; j < n; j++) {

                    if (board[i][j] == 1)
                        s += 'Q';
                    else
                        s += '.';
                }

                solution.push_back(s);
            }

            result.push_back(solution);
            return;
        }

        for (int col = 0; col < n; col++) {

            if (isSafe(board, row, col, n)) {

                board[row][col] = 1;

                solveNQueens(board, row + 1, n, result);

                board[row][col] = 0;
            }
        }
    }

public:

    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> result;

        vector<vector<int>> board(n, vector<int>(n, 0));

        solveNQueens(board, 0, n, result);

        return result;
    }
};