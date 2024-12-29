class Solution {
public:
    int MOD = 1e9+7;
    int dp[1002][1002];
    int mp[1002][27];
    int numWays(vector<string>& words, string target) {

        // preprocess word data.
        int m = words[0].length();
        int n = target.length();
        
        for(int i=0;i<m;i++){ 
            for(string word : words){
                mp[i][word[i] - 'a']++;
            }
        }

        for(int i=0;i<=m;i++){
            dp[0][i] = 1;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                dp[i][j] = (1LL * (mp[j-1][target[i-1]-'a'] % MOD) * (dp[i-1][j-1] % MOD) + dp[i][j-1]) % MOD;
            }
        }

        return dp[n][m];

    }
};