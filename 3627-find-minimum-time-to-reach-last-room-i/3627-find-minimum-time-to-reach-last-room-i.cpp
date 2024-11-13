#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& m) {
        int rows = m.size();
        int cols = m[0].size();
        
        // Priority queue stores {current_time, i, j}
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.push({0, 0, 0});
        
        // DP array to store the minimum time to reach each cell
        vector<vector<long>> dp(rows, vector<long>(cols, 1e10));
        dp[0][0] = 0;
        
        // Possible moves in 4 directions
        int di[4] = {1, 0, -1, 0};
        int dj[4] = {0, -1, 0, 1};
        
        while (!pq.empty()) {
            auto [curr_time, i, j] = pq.top();
            pq.pop();
            
            // If we reach the bottom-right corner, return the time
            if (i == rows - 1 && j == cols - 1) {
                return curr_time;
            }
            
            for (int k = 0; k < 4; ++k) {
                int ni = i + di[k];
                int nj = j + dj[k];
                
                if (ni >= 0 && nj >= 0 && ni < rows && nj < cols && m[ni][nj] != -1) {
                    int new_time = max(curr_time, m[ni][nj]) + 1;
                    
                    // Only proceed if we find a faster way to reach cell (ni, nj)
                    if (new_time < dp[ni][nj]) {
                        dp[ni][nj] = new_time;
                        pq.push({new_time, ni, nj});
                    }
                }
            }
        }
        
        return -1; // If the destination is unreachable
    }
};
