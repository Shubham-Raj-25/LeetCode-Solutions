class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long topSum =0, bottomSum = 0;
        for(auto it:grid[0]) topSum += it;
        long long ans = LLONG_MAX;
        for(int i=0;i<grid[0].size();i++){
            topSum -= grid[0][i];
            ans = min(ans,max(topSum,bottomSum));
            bottomSum += grid[1][i];
        }
        return ans;
    }
};