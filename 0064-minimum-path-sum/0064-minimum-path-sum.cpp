class Solution {
public:
    int func(int i, int j,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(i >= grid.size() || j >= grid[0].size())
            return 1e8;
        
        if(i==grid.size()-1 && j==grid[0].size()-1)
            return grid[i][j];
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int right = func(i+1,j,grid,dp);
        int down = func(i,j+1,grid,dp);

        return dp[i][j] = grid[i][j] + min(right,down);
    }

    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(),-1));
        return func(0,0,grid,dp);
    }
};