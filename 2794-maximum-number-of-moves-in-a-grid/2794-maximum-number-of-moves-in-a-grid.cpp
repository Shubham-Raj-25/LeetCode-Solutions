class Solution {
public:
    int func(int r, int c,vector<vector<int>>& dp,vector<vector<int>>& grid){
        int rows = grid.size();
        int cols = grid[0].size();

        if(dp[r][c]!=-1) return dp[r][c];
        int ans = 0;
        int dr[3] = {-1,0,1};
        for(int i=0;i<3;i++){
            int nr = r+dr[i];
            int nc = c+1;

            if(nr>=0 && nr<rows && nc<cols && grid[r][c]<grid[nr][nc] && grid[nr][nc]>0)
                ans = max(ans, 1+func(nr,nc,dp,grid));
            
        }

        return dp[r][c]=ans;
    }

    int maxMoves(vector<vector<int>>& grid) {
      
      int ans = 0;
      vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
      for(int i=0;i<grid.size();i++)
          ans = max(ans,func(i,0,dp,grid));

      return ans;  
    }
};
