class Solution {
public:
    bool hasCycle(int i, int j,char c, int pi, int pj, vector<vector<char>>& grid,vector<vector<bool>>& vis){
        int m = grid.size();
        int n = grid[0].size();

        if(vis[i][j])
            return true;
        vis[i][j] = true;

        int di[4] = {0,1,0,-1};
        int dj[4] = {-1,0,1,0};

        for(int k=0;k<4;k++){
            int ni = i+di[k];
            int nj = j+dj[k];
            if((ni!=pi || nj!=pj) && (ni>=0 && ni<m) && (nj>=0 && nj<n) && grid[ni][nj] == c){
                if(hasCycle(ni,nj,c,i,j,grid,vis))
                    return true;
            }
        }

        return false;
    }
    
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(!vis[i][j])
                    if(hasCycle(i,j,grid[i][j],-1,-1,grid,vis))
                        return true;
                
        return false;    
    }
};