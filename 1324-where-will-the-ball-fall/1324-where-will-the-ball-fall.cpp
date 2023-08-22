class Solution {
public:
    int func(int r, int c, vector<vector<int>>& grid,  map<pair<int,int>,int>& dp){
        
        if(r==grid.size()) return c;

        if(dp.find({r,c})!=dp.end()) return dp[{r,c}];

        if((c==grid[0].size()-1 && grid[r][c]==1) || (c==0 && grid[r][c]==-1) || 
            (grid[r][c]==1 && grid[r][c+1]==-1) || (grid[r][c]==-1 && grid[r][c-1]==1))
            return -1;

        if(grid[r][c]==1)
            dp[{r,c}] = func(r+1,c+1,grid,dp);
        else
            dp[{r,c}] = func(r+1,c-1,grid,dp);
        
        return dp[{r,c}];

    }

    vector<int> findBall(vector<vector<int>>& grid) {
        map<pair<int,int>,int> dp;
        int m = grid[0].size();
        vector<int> ans(m,-1);
        for(int i=0;i<m;i++){
            
            ans[i] = func(0,i,grid,dp);
        }
        return ans;
    }
};