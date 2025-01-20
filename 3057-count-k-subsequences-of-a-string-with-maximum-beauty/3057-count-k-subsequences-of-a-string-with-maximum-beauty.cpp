class Solution {
public:
    int mod = 1e9 + 7;
    int tar;
    int dp[26][26];
    
    long dfs(int idx,int k,vector<int>& f){
        if(k == tar)
            return 1;
        if(idx == f.size() || f[idx] < f[k])
            return 0;
        if(dp[idx][k] != -1)
            return dp[idx][k];
        long res = 0;
        //take
        if(f[idx] == f[k]) // this is to make sure to take the top k 
            res = (f[idx] * dfs(idx+1,k+1,f))%mod;
        //no take
        res = (res + dfs(idx+1,k,f))%mod;
        return dp[idx][k] = res;
    }
    
    int countKSubsequencesWithMaxBeauty(string s, int k) {
        memset(dp,-1,sizeof(dp));
        int count = 0;
        tar = k;
        vector<int> f(26,0);
        for(char& c:s){
            if(++f[c - 'a'] == 1)
                count++;
        }
        sort(f.begin(),f.end(),greater<>());
        if(count < k)
            return 0;
        return dfs(0,0,f);
    }
};