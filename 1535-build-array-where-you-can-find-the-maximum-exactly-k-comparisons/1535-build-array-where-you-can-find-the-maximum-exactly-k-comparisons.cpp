class Solution {
public:
    
    long long dp[51][101][51];
    int mod = 1e9+7;

    int numOfArrays(int n, int m, int k) {
    
        for(int i=1;i<=m;i++)
            dp[1][i][1] = 1;
        
        // filling dp

        for(int a=1;a<=n;a++){
            for(int b=1;b<=m;b++){
                for(int c=1;c<=k;c++){
                    long long data = 0;

                    data =b*dp[a-1][b][c]%mod;

                    for(int x=1;x<b;x++)
                        data = (data + dp[a-1][x][c-1])%mod;
                    
                    dp[a][b][c] = (dp[a][b][c] + data)%mod;

                }
            }
        }

        long long ans = 0;

        for(int j=1;j<=m;j++)
            ans = (ans+dp[n][j][k])%mod;
        
        return (ans);

    }
};