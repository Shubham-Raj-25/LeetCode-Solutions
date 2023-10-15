class Solution {
public:
    int mod = 1e9+7;
    map<pair<int,int>,long long> dp;

    int func(int steps, int arrLen, int steps_taken,int sum){
        if(sum <0 || sum >= arrLen)
            return 0;
        if(steps_taken == steps)
            return sum == 0 ? 1 : 0 ;

        if(dp.find({steps_taken,sum})!=dp.end())
            return dp[{steps_taken,sum}];
        
        //take left
        int left = func(steps,arrLen,steps_taken+1,sum-1)%mod;
        
        //stay
        int stay = func(steps,arrLen,steps_taken+1,sum)%mod;

        // take right
        int right = func(steps,arrLen,steps_taken+1,sum+1)%mod;


        return dp[{steps_taken,sum}] =  ((left%mod+right%mod)%mod+stay%mod)%mod;
    }


    int numWays(int steps, int arrLen) {
        return func(steps,arrLen,0,0);

    }
};