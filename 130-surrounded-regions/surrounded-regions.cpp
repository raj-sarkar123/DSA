class Solution {
public:
    bool isvalid(int i, int j, int n, int m) {
        if (i < 0 || i >= n || j < 0 || j >= m) {
            return false;
        }
        return true;
    }
    int x[4] = {1, -1, 0, 0};
    int y[4] = {0, 0, 1, -1};

    void dfs(vector<vector<char>>& board, int i, int j, int m, int n) {
        board[i][j] = '#';
        for (int k = 0; k < 4; k++) {
            int row = i + x[k];
            int col = j + y[k];

            if (isvalid(row, col, n, m) && board[row][col] == 'O') {
                dfs(board, row, col, m, n);
            }
        }
        return;
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        // First row
        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O') {
                dfs(board, 0, j, m, n);
            }
        }
        // Second row
        for (int j = 0; j < m; j++) {
            if (board[n - 1][j] == 'O') {
                dfs(board, n - 1, j, m, n);
            }
        }
        // Frist column
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') {
                dfs(board, i, 0, m, n);
            }
        }
        // Second column
        for (int i = 0; i < n; i++) {
            if (board[i][m - 1] == 'O') {
                dfs(board, i, m - 1, m, n);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == '#') {
                    board[i][j] = 'O';
                } else {

                    board[i][j] = 'X';
                }
            }
        }
    }
};