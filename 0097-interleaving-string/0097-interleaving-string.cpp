class Solution {
public:
    bool func(int i, int j, string temp, string s1, string s2, string s3, vector<vector<int>>& dp){

        if(temp == s3)
            return true;
        
        if(i==s1.length())
            return temp + s2.substr(j) == s3;
        
        if(j==s2.length())
            return temp + s1.substr(i) == s3;

        if(dp[i][j]!=-1)
            return dp[i][j];
        
        bool ans = false;
        //trick here is to take one element at a time, not substr

        if(s1[i] == s3[i+j])
            ans = ans || func(i+1,j,temp+s1[i],s1,s2,s3,dp);
            
        if(s2[j] == s3[i+j])
            ans = ans || func(i,j+1,temp+s2[j],s1,s2,s3,dp);
        
        return dp[i][j] = ans;

    }

    bool isInterleave(string s1, string s2, string s3) {

        if(s1.length() + s2.length() != s3.length())
            return false;
        
        int n = s1.length();
        int m = s2.length();

        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));

        return func(0,0,"",s1,s2,s3,dp);
    }
};