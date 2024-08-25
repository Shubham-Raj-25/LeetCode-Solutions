class Solution {
public:
    bool func(int i, int j,int idx, vector<vector<int>>& vis, vector<vector<char>>& board, string& word){
        if(idx == word.length())
            return true;
        
        int di[4] = {1,0,-1,0};
        int dj[4] = {0,-1,0,1};

        for(int k=0;k<4;k++){
            int ni = i + di[k], nj = j + dj[k];
            if(ni >=0 && ni <board.size() && nj >=0 && nj < board[0].size() && board[ni][nj] == word[idx] && vis[ni][nj]==0){
                vis[ni][nj] = 1;
                if(func(ni,nj,idx+1,vis,board,word))
                    return true;
                vis[ni][nj] = 0;
            }
        }

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        
        vector<vector<int>> vis(m, vector<int>(n,0));
        
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(board[i][j] == word[0]){
                    vis[i][j] = 1;
                    if(func(i,j,1,vis,board,word))
                        return true;
                    vis[i][j] = 0;
                }
        
        return false;
    }
};