class Solution {
public:
    int helper(int i, int j,vector<vector<int>>& dp, string& text1, string& text2){
        
        if(i == text1.length() || j == text2.length()){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int op1 = 0, op2 = 0, op3 = 0;

        if(text1[i] == text2[j]){
            op1 = 1 + helper(i+1,j+1,dp,text1,text2);
        }
        else{
            op2 = helper(i+1,j,dp,text1,text2);
            op3 = helper(i,j+1,dp,text1,text2);
        }
        return dp[i][j] = max(op1,(int)max(op2,op3));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        vector<vector<int>> dp(n, vector<int> (m,-1));
        return helper(0,0,dp,text1,text2);
    }
};