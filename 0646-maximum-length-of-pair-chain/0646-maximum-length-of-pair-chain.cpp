class Solution {
public:
    int func(int idx, int last, vector<vector<int>>& pairs,  vector<vector<int>>& dp){
        if(idx==pairs.size())
            return 0;
        
        if(dp[idx][last+1]!=-1)
            return dp[idx][last+1];

        int pick = 0, notPick = 0;

        if(last == -1 || pairs[last][1] < pairs[idx][0])
            pick = 1 + func(idx+1,idx,pairs,dp);
        
        notPick = func(idx+1,last,pairs,dp);

        return dp[idx][last+1] = max(pick,notPick);
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        int n = pairs.size();
        vector<vector<int>>dp(n+1,vector<int>(n+2,-1));
        return func(0,-1,pairs,dp);
    }
};