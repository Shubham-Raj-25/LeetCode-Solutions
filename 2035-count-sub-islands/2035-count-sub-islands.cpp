class Solution {
public:
    bool is_sub_island(int i, int j, vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        if (grid2[i][j] == 0) return true;
        if (grid1[i][j] == 0) return false;
        
        grid2[i][j] = 0;  // Mark as visited
        
        bool is_sub = true;
        int di[4] = {1, 0, -1, 0};
        int dj[4] = {0, -1, 0, 1};

        for (int k = 0; k < 4; ++k) {
            int ni = i + di[k], nj = j + dj[k];
            if (ni >= 0 && nj >= 0 && ni < grid2.size() && nj < grid2[0].size()) {
                if (!is_sub_island(ni, nj, grid1, grid2))
                    is_sub = false;
            }
        }

        return is_sub;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int ans = 0;

        for (int i = 0; i < grid2.size(); ++i) {
            for (int j = 0; j < grid2[0].size(); ++j) {
                if (grid2[i][j] == 1) {
                    if (is_sub_island(i, j, grid1, grid2)) {
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};
