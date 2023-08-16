class Solution {
public:
    bool func(int i, int j, string temp, string s1, string s2, string s3, vector<vector<int>>& dp) {
        if (temp == s3) {
            return true;
        }
        
        if (i >= s1.length()) {
            return temp + s2.substr(j) == s3;
        }
        
        if (j >= s2.length()) {
            return temp + s1.substr(i) == s3;
        }
        
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        
        bool result = false;
        if (s1[i] == s3[i + j]) {
            result = result || func(i + 1, j, temp + s1[i], s1, s2, s3, dp);
        }
        if (s2[j] == s3[i + j]) {
            result = result || func(i, j + 1, temp + s2[j], s1, s2, s3, dp);
        }
        
        dp[i][j] = result;
        return dp[i][j];
    }

    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length()) {
            return false;
        }
        
        vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, -1));
        return func(0, 0, "", s1, s2, s3, dp);
    }
};
