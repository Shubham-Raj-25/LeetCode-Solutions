class Solution {
public:
    int dp[501][501][5][2][3];
    int func(int i, int j, int dir, int canTurn, int last, vector<vector<int>>& grid){
        if(i >= grid.size() || j >= grid[0].size() || i < 0 ||  j < 0){
            return 0;
        }

        if(dp[i][j][dir][canTurn][last] != -1){
            return dp[i][j][dir][canTurn][last];
        }

        if(last == 0 && grid[i][j] != 2){
            return 0;
        }

        if(last == 2 && grid[i][j] != 0){
            return 0;
        }

        if(last == 1 && grid[i][j] != 2){
            return 0;
        }

        int ans = 0;
    
        if(dir == 1){
            ans = 1 + func(i-1,j-1,1,canTurn,grid[i][j],grid);
            if(canTurn){
                ans = max(ans, 1 + func(i-1,j+1,2,0,grid[i][j],grid));
            }
        }

        if(dir == 2){
            ans = 1 + func(i-1,j+1,2,canTurn,grid[i][j],grid);
            if(canTurn){
                ans = max(ans, 1 + func(i+1,j+1,3,0,grid[i][j],grid));
            }
        }

        if(dir == 3){
            ans = 1 + func(i+1,j+1,3,canTurn,grid[i][j],grid);
            if(canTurn){
                ans = max(ans, 1 + func(i+1,j-1,4,0,grid[i][j],grid));
            }
        }

        if(dir == 4){
            ans = 1 + func(i+1,j-1,4,canTurn,grid[i][j],grid);
            if(canTurn){
                ans = max(ans, 1 + func(i-1,j-1,1,0,grid[i][j],grid));
            }
        }

        return dp[i][j][dir][canTurn][last] = ans;
    }

    int lenOfVDiagonal(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        int ans = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 1){
                    ans = max(ans, 1 + func(i-1,j-1,1,1,1,grid));
                    ans = max(ans, 1 + func(i-1,j+1,2,1,1,grid));
                    ans = max(ans, 1 + func(i+1,j+1,3,1,1,grid));
                    ans = max(ans, 1 + func(i+1,j-1,4,1,1,grid));
                }
            }
        }

        return ans;
    }
};
/*

simulation ? 
4d dp
i,j,direction,canTurn
500 * 500 * 5 * 2= 25 * 10^5 != MLE
map<vector<int>,int> cache

*/ 