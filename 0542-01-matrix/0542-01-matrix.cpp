class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> ans(m,vector<int>(n,0));
        vector<vector<int>> vis(m,vector<int>(n,0));

        queue<pair<pair<int,int>,int>> q;

        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(mat[i][j]==0)
                    q.push({{i,j},0});
        

        int dr[4] = {1,0,-1,0};
        int dc[4] = {0,-1,0,1};

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            cout << row << "  " << col << endl;
            if(mat[row][col]==1)
                ans[row][col] = steps;

            for(int i=0;i<4;i++){
                int nr = row+dr[i];
                int nc = col+dc[i];

                if(nr>=0 && nc>=0 && nr<m && nc<n && vis[nr][nc]==0){
                    vis[nr][nc]=1;
                    q.push({{nr,nc},steps+1});
                }
            }
        }

        return ans;

    }
};