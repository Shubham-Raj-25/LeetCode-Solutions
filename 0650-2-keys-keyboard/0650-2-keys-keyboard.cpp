class Solution {
public:
    map<pair<int,int>,int> dp;

    int func(int curr, int n, int copy){
        if(curr==n)
            return 0;
        if(curr > n || copy > n)
            return 1e4;
        
        if(dp.find({curr,copy})!=dp.end())
            return dp[{curr,copy}];
        
        int COPY = 1e4 , PASTE = 1e4;

        // copy
        if(curr!=copy) // no benefit copying the same length
            COPY = 1+func(curr,n,curr);
        
        // paste
        if(copy!=0)    // paste only when there's something to paste
            PASTE = 1+func(curr+copy,n,copy);

        return dp[{curr,copy}] = min(COPY,PASTE);
    }   

    int minSteps(int n) {
        if(n==1) return 0;

        return func(1,n,0);
    }
};