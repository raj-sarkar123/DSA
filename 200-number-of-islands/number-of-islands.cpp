class Solution {
public:
    int x[4] = {-1, 1, 0, 0};
    int y[4] = {0, 0, -1, 1};
    bool valid(int i, int j, int n, int m) {
        if (i < 0 || j < 0 || i >= n || j >= m) {
            return false;
        }
        return true;
    }
    void dfs(vector<vector<char>>& arr, vector<vector<bool>>& visited, int n,
             int m, int i, int j) {
        visited[i][j] = 1;
        for (int k = 0; k < 4; k++) {
            int row = i + x[k];
            int col = j + y[k];
            if (valid(row, col, n, m) && arr[row][col] == '1' && visited[row][col] == 0) {
                dfs(arr, visited, n, m, row, col);
            }
        }
            return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        int n = grid.size();
        int m = grid[0].size();
        int i, j;
        vector<vector<bool>> visited(n);
        for (int b = 0; b < n; b++) {
            vector<bool> t(m, 0);
            visited[b] = t;
        }

        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                if (grid[i][j] == '1' && visited[i][j] == 0) {
                    dfs(grid, visited, n, m, i, j);
                    res++;
                }
            }
        }
        return res;
    }
};