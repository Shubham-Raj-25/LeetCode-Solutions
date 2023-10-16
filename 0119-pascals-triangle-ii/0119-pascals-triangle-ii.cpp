class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int dp[35][35];

        dp[0][0] = 1;
        dp[1][0] = 1;
        dp[1][1] = 1;

        for(int row = 2; row <= rowIndex; row++){
            dp[row][0] = 1;
            dp[row][row] = 1;

            for(int col=1;col<row;col++)
                dp[row][col] = dp[row-1][col-1] + dp[row-1][col];
            
        }

        vector<int> ans;
        for(int i=0;i<=rowIndex;i++)
            ans.push_back(dp[rowIndex][i]);

        return ans; 
    }
};