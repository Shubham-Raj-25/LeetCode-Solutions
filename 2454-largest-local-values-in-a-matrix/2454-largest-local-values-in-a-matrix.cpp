class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> ans(n-2,vector<int>(n-2,0));

        for(int i=0;i<=n-3;i++){
            for(int j=0;j<=n-3;j++){
                int maxi = 0;
                for(int r=i;r<i+3;r++){
                    for(int c=j;c<j+3;c++)
                        maxi = max(maxi,grid[r][c]);
                }
                ans[i][j] = maxi;
            }
        }

        return ans;
    }
};