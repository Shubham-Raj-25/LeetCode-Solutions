class Solution {
public:
    int catchFish(int i, int j,vector<vector<int>>& grid){
        int totalCatch = grid[i][j];
        grid[i][j] = 0;

        int dr[4] = {1,0,-1,0};
        int dc[4] = {0,-1,0,1};

        for(int k=0;k<4;k++){
            int nr = i + dr[k];
            int nc = j + dc[k];
            if(nr >=0 && nc >= 0 && nr < grid.size() && nc < grid[0].size() && grid[nr][nc]){
                totalCatch += catchFish(nr,nc,grid);
            }
        }
        return totalCatch;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int maxi = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]){
                    maxi = max(maxi, catchFish(i,j,grid));
                }
            }
        }
        return maxi;
    }
};