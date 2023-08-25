class Solution {
public:
    
    map<pair<int,long long>,int> mp;

    long long func(int n, int sum, long long prod){
        if(sum==n)
            return prod;
        
        if(sum > n)
            return 1;
        
        if(mp.find({sum,prod})!=mp.end())
            return mp[{sum,prod}];

        long long ans = 1;

        for(int i=1;i<n;i++){
            ans = max(ans, func(n,sum+i,prod*i));
        }

        return mp[{sum,prod}] = ans;
    }

    int integerBreak(int n) {
        // looks like a dp problem
        return func(n,0,1);
    }
};