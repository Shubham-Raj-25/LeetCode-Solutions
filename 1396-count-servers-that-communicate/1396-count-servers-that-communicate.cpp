class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        unordered_map<int,int> row, col;
        for(int i=0;i<grid.size();i++){
            int count = 0;
            for(int j=0;j<grid[0].size();j++)
                if(grid[i][j]==1)
                    count++;
            row[i] = count;
        }

        for(int i=0;i<grid[0].size();i++){
            int count = 0;
            for(int j=0;j<grid.size();j++)
                if(grid[j][i]==1)
                    count++;
            col[i] = count;
        }

        int ans = 0;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    if(row[i]>1 || col[j]>1)
                        ans++;
                }
            }
        }

        return ans;
    }
};