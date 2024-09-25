class Solution {
public:
    int func(int i, int j, string& word1, string& word2,vector<vector<int>>& dp){
        if(i == word1.length() || j == word2.length())
            return word1.length() - i + word2.length()-j;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int both_match = INT_MAX, del = INT_MAX, replace = INT_MAX, insert = INT_MAX;
        if(word1[i] == word2[j])
            both_match = func(i+1,j+1,word1,word2,dp);
        else{
            del = 1+func(i+1,j,word1,word2,dp);
            replace = 1+func(i+1,j+1,word1,word2,dp);
            insert = 1 + func(i,j+1,word1,word2,dp);
        }
        return dp[i][j] = min(both_match, min(del,min(insert,replace)));
    }

    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length(), vector<int> (word2.length(),-1));
        return func(0,0,word1,word2,dp);
    }
};