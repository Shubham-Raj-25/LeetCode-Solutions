class Solution {
public:
    int simulate_child_2(int r, int c, vector<vector<int>>& dp,vector<vector<int>>& fruits){
        if(r == fruits.size() -1 && c == fruits.size() -1 || r>=c)  
            return 0;
        if(dp[r][c] != -1)
            return dp[r][c];
        
        int max_fruits = 0;

        if(c+1 < fruits.size())
            max_fruits = fruits[r][c] + simulate_child_2(r+1,c+1,dp,fruits);
        max_fruits = max(max_fruits, fruits[r][c] + simulate_child_2(r+1,c-1,dp,fruits));
        max_fruits = max(max_fruits, fruits[r][c] + simulate_child_2(r+1,c,dp,fruits));

        return dp[r][c] = max_fruits;
    }

    int simulate_child_3(int r, int c, vector<vector<int>>& dp,vector<vector<int>>& fruits){
        if(r == fruits.size() -1 && c == fruits.size() -1 || c>=r)  
            return 0;
        if(dp[r][c] != -1)
            return dp[r][c];
        
        int max_fruits = 0;

        if(r+1 < fruits.size())
            max_fruits = fruits[r][c] + simulate_child_3(r+1,c+1,dp,fruits);
        max_fruits = max(max_fruits, fruits[r][c] + simulate_child_3(r-1,c+1,dp,fruits));
        max_fruits = max(max_fruits, fruits[r][c] + simulate_child_3(r,c+1,dp,fruits));

        return dp[r][c] = max_fruits;
    }

    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();
        vector<vector<int>> dp1(n,vector<int>(n,-1)), dp2(n,vector<int>(n,-1));
        int child1 = 0, child2 = 0, child3 = 0;
        
        for(int i=0;i<n;i++)
            child1 += fruits[i][i];
        
        child2 = simulate_child_2(0,n-1,dp1,fruits);
        child3 = simulate_child_3(n-1,0,dp2,fruits);

        return child1 + child2 + child3;
    }
};