class Solution {
public:
    int func(int n,int row,int col,vector<vector<int>>& triangle, vector<vector<int>>& dp){
        
        if(row==n-1) return triangle[row][col];

        if(dp[row][col]!=-1) return dp[row][col];

        int down = triangle[row][col]+func(n,row+1,col,triangle,dp);
        int diag = triangle[row][col]+func(n,row+1,col+1,triangle,dp);

        return dp[row][col] = min(diag,down);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n = triangle.size();

        vector<vector<int>> dp(n,vector<int>(n,-1));

        return func(n,0,0,triangle,dp);
    }
};