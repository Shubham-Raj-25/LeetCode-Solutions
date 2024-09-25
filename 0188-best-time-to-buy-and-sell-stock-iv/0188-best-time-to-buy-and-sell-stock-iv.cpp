class Solution {
public:
    int func(int day, int can_buy, int k, vector<int>& prices, vector<vector<vector<int>>>& dp){
        if(day == prices.size() || k < 0)
            return 0;
        
        if(dp[day][k][can_buy] != -1)
            return dp[day][k][can_buy];
        
        int max_profit = 0;

        if(can_buy){
            max_profit = max(max_profit, -prices[day] + func(day+1,0,k-1,prices,dp)); // buy
        }else{
            max_profit = max(max_profit, prices[day] + func(day+1,1,k,prices,dp)); // sell
        }
        max_profit = max(max_profit, func(day+1,can_buy,k,prices,dp)); // don't do anything
        
        return dp[day][k][can_buy] = max_profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(k+1, vector<int>(2,-1)));
        return func(0,1,k,prices,dp);
    }
};