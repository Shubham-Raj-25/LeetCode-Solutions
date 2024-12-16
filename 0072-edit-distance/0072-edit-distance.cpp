class Solution {
public:
    int func(int i,int j,vector<vector<int>>& dp, string& w1, string& w2){
        if(i == w1.length()){
            return w2.length() - j;
        }

        if(j == w2.length()){
            return w1.length() - i;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int min_operations = INT_MAX;

        if(w1[i] == w2[j]){
            min_operations = func(i+1,j+1,dp,w1,w2);
        }
        else{
            // inserting
            int insert_case = 1+func(i,j+1,dp,w1,w2);
            // deleting
            int delete_case = 1+func(i+1,j,dp,w1,w2);
            // replacing
            int replace_case = 1+func(i+1,j+1,dp,w1,w2);
            min_operations = min(min_operations, (int)min(insert_case,(int)min(delete_case,replace_case)));
        }

        return dp[i][j] = min_operations;
    }

    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

        for(int j=0;j<=m;j++){
            dp[n][j] = m-j;
        }

        for(int i=0;i<=n;i++){
            dp[i][m] = n-i;
        }

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(word1[i] == word2[j]){
                    dp[i][j]  = dp[i+1][j+1];
                }
                else{
                    dp[i][j] = 1 + min(dp[i+1][j], (int)min(dp[i+1][j+1],dp[i][j+1]));
                }
            }
        }

        return dp[0][0];
    }
};

