class Solution {
public:
    bool isvalid(int i, int j, vector<vector<int>>& grid,
                 vector<vector<int>>& helpcol, vector<vector<int>>& helprow) {
        unordered_map<int, int> umap;
        int n = grid.size();
        int m = grid[0].size();

        // Check if (i, j) can be the center of a 3x3 subgrid
        if (i - 1 < 0 || j - 1 < 0 || i + 1 >= n || j + 1 >= m) {
            return false;
        }

        // Check if the 3x3 subgrid has unique values from 1 to 9
        if (i - 1 >= 0 && j - 1 >= 0 && i + 1 < n && j + 1 < m) {
            int drow[] = {-1, -1, -1, 0, 1, 1, 1, 0};
            int dcol[] = {-1, 0, 1, 1, 1, 0, -1, -1};

            for (int k = 0; k < 8; k++) {
                int nr = i + drow[k];
                int nc = j + dcol[k];
                if (umap.find(grid[nr][nc]) != umap.end())
                    return false;
                if (grid[nr][nc] < 1 || grid[nr][nc] > 9)
                    return false;
                umap[grid[nr][nc]]++;
            }

            int val = helprow[i - 1][j + 1];
            if (helprow[i][j + 1] == val && helprow[i + 1][j + 1] == val) {
                if (helpcol[i + 1][j + 1] == val && helpcol[i + 1][j] == val &&
                    helpcol[i + 1][j - 1] == val) {
                    if (grid[i][j] + grid[i - 1][j - 1] + grid[i + 1][j + 1] == val) {
                        if (grid[i][j] + grid[i - 1][j + 1] + grid[i + 1][j - 1] == val) {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if (n < 3 || m < 3)
            return 0;

        vector<vector<int>> helprow = grid;
        vector<vector<int>> helpcol = grid;

        // Compute prefix sums for rows
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (j - 3 >= 0) {
                    helprow[i][j] = helprow[i][j - 1] - grid[i][j - 3] + helprow[i][j];
                } else {
                    helprow[i][j] += helprow[i][j - 1];
                }
            }
        }

        // Compute prefix sums for columns
        for (int i = 0; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (j - 3 >= 0) {
                    helpcol[j][i] = helpcol[j - 1][i] - grid[j - 3][i] + helpcol[j][i];
                } else {
                    helpcol[j][i] += helpcol[j - 1][i];
                }
            }
        }

        int cnt = 0;

        // Check each cell as the center of a 3x3 subgrid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (isvalid(i, j, grid, helpcol, helprow)) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};