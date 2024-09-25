class Solution {
public:
    int func(int i,int j,string& t1, string& t2, vector<vector<int>>& dp){
        if(i == t1.length() || j == t2.length())
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int both_equal = 0, inc_i = 0, inc_j = 0;

        if(t1[i] == t2[j])
            both_equal = 1 + func(i+1,j+1,t1,t2,dp);
        else{
            inc_i = func(i+1,j,t1,t2,dp);
            inc_j = func(i,j+1,t1,t2,dp);
        }

        return dp[i][j] = max(both_equal, max(inc_i,inc_j));
    }
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.length(), vector<int>(s.length(),-1));
        string rev_s = s;
        reverse(s.begin(),s.end());
        return func(0,0,s,rev_s,dp);
    }
};