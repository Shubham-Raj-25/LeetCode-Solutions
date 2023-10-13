class Solution {
public:
    unordered_map<int,int> cache;
    int func(int curr,vector<int>& cost){
        if(curr >= cost.size())
            return 0;
        
        if(cache.find(curr)!= cache.end())
            return cache[curr];
        
        return cache[curr] =  min(func(curr+1,cost),func(curr+2,cost))+cost[curr];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        return min(func(0,cost),func(1,cost));
    }
};