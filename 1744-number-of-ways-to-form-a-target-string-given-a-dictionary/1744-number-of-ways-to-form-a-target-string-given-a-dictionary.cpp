class Solution {
int mod=1e9+7;

private:
    long long ex(int i, int j, int n, map<char,int> *hash, string &target, vector<vector<int>> &dp){
        if(j>=target.size()) return 1;
        if(i>=n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        long long ans=0;
        if(hash[i][target[j]]>0){
            long long take=hash[i][target[j]]*ex(i+1,j+1,n,hash,target,dp)%mod;
            ans=(ans+take)%mod;
        }
        long long not_take=ex(i+1,j,n,hash,target,dp)%mod;
        ans=(ans+not_take)%mod;

        return dp[i][j]=ans;
    }

public:
    int numWays(vector<string>& words, string target) {
        map<char,int> hash[words[0].size()];
        for(int i=0; i<words.size(); i++){
            for(int j=0; j<words[i].size(); j++){
                hash[j][words[i][j]]++;
            }
        }

        vector<vector<int>> dp(words[0].size(), vector<int>(target.size(),-1));
        return (int)ex(0,0,words[0].size(),hash,target,dp);
    }
};