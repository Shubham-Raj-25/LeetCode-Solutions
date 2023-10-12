class Solution {
public:
    int minOperations(string s1, string s2, int x) {
        int n = s1.length();
        vector<int> diff;

        for(int i=0;i<n;i++)
            if(s1[i]!=s2[i])
                diff.push_back(i);
        
        if(diff.size()%2!=0) return -1;

        n = diff.size();

        vector<int> dp(n+1,1000000);

        dp[0] = 1;

        for(int i=1;i<=n;i++){
            cout << i << endl;
            dp[i] = dp[i-1] + x;
            if(i>=2)
            dp[i] = min(dp[i], dp[i-2] + 2*(diff[i-1]-diff[i-2]));
        }

        return dp[n]/2;

    }
};