class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        deque<pair<int, int>> q;
        q.push_front({0, 0});
        dp[0][0] = 0;

        int dx[4] = {0, 1, -1, 0};
        int dy[4] = {1, 0, 0, -1};

        while (!q.empty()) {
            auto [cx, cy] = q.front();
            q.pop_front();

            for (int k = 0; k < 4; k++) {
                int nx = cx + dx[k];
                int ny = cy + dy[k];

                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    int newCost = dp[cx][cy] + grid[nx][ny];
                    if (newCost < dp[nx][ny]) {
                        dp[nx][ny] = newCost;
                        if (grid[nx][ny]) {
                            q.push_back({nx, ny});
                        } else {
                            q.push_front({nx, ny});
                        }
                    }
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};
