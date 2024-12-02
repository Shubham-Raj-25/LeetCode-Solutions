class Solution {
private:
    int m;
    int n;
public:
    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& vis){
        vis[i][j] = true;
        int di[4] = {1,0,-1,0};
        int dj[4] = {0,-1,0,1};
        for(int k=0;k<4;k++){
            int ni = i + di[k];
            int nj = j + dj[k];
            if(ni>=0 && nj>=0 && ni<m && nj<n && grid[ni][nj] == '1' && !vis[ni][nj])
                dfs(ni,nj,grid,vis);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n,false));
        int islands = 0;

        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    islands++;
                    dfs(i,j,grid,vis);
                }
            }

        return islands;
    }
};