class Solution {
public:
    int numTilings(int n) {
        // 1 -> 1
        // 2 -> 2
        // 3 -> 5
        // 4 -> 11
        // 5 -> 24
        // 6 -> 53
        // here as we can observe, dp[i] = 2*dp[i-1]*dp[i-3];
        int mod = 1e9+7;

        vector<long long> dp(n+5,0);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;

        if(n<=3) return dp[n];

        for(int i=4;i<=n;i++)
            dp[i] = (2*dp[i-1] + dp[i-3])%mod;
        
        return dp[n]%mod;
    }
};