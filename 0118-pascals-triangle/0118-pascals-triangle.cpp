class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows==1) return {{1}};
        vector<vector<int>> dp(numRows);
        dp[0] = {1};
        dp[1] = {1,1};
    
        for(int i=2;i<numRows;i++){
            vector<int> temp;
            temp.push_back(1);
            for(int j=0;j<(int)dp[i-1].size()-1;j++)
                    temp.push_back(dp[i-1][j]+dp[i-1][j+1]);
            temp.push_back(1);
            dp[i]=temp;
        }
        return dp; 
    }
};