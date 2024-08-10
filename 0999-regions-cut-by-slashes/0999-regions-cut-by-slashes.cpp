class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>& vis,vector<vector<int>>& sqr){
        int n = vis.size();
        vis[r][c] = 1;

        int dr[4] = {0,1,0,-1};
        int dc[4] = {-1,0,1,0};

        for(int k=0;k<4;k++){
            int nr = r + dr[k];
            int nc = c + dc[k];
            if(nr>=0 && nr<n && nc>=0 && nc<n && sqr[nr][nc]+vis[nr][nc] == 0)
                dfs(nr,nc,vis,sqr);
        }
    }
    
    int regionsBySlashes(vector<string>& grid) {
        int n =  grid.size();
        vector<vector<int>> sqr(3*n,vector<int>(3*n,0)), vis(3*n,vector<int>(3*n,0));

        int r = 0, c = 0;
        for(string s: grid){
            c = 0;
            for(int i = 0; i<s.length();i++){
                if(s[i] == '/'){
                    // cout << "here r and c and i are " << r << " " << c << " " << i << endl;
                    sqr[r][c+2] = 1;
                    sqr[r+1][c+1] = 1;
                    sqr[r+2][c] = 1;
                }
                else if(s[i] == '\\'){
                    sqr[r][c] = 1;
                    sqr[r+1][c+1] = 1;
                    sqr[r+2][c+2] = 1;
                }
                c += 3;
            }
            r += 3;
        }
        // for(int i=0;i<2*n;i++){
        //     for(int j=0;j<2*n;j++)
        //         cout << sqr[i][j] << " ";
        //     cout << endl;
        // }
        int ans = 0;

        for(int i=0;i<3*n;i++){
            for(int j=0;j<3*n;j++){
                if(sqr[i][j] + vis[i][j] == 0){
                    ans++;
                    dfs(i,j,vis,sqr);
                }
            }
        }

        return ans;
    }
};