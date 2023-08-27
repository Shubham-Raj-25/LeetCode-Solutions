class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& vis, vector<vector<char>>& board){
        if(board[i][j] == '.')
            return;
        
        int dr[2] = {1,0};
        int dc[2] = {0,1};

        for(int k=0;k<2;k++){
            int nr = i+dr[k];
            int nc = j+dc[k];
            if(nr<board.size() && nc<board[0].size() && board[i][j]=='X'){
                vis[nr][nc] = 1;
                dfs(nr,nc,vis,board);
            }
        }

    }

    int countBattleships(vector<vector<char>>& board) {
        int ans = 0;
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m, vector<int>(n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == 'X' && !vis[i][j]){
                    vis[i][j] = 1;
                    dfs(i,j,vis,board);
                    ans++;
                }
            }
        }

        return ans;
    }
};