class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size(), ans = 0;
        vector<int> rowData(rows,0), colData(cols,0);
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j] == 1){
                    rowData[i]++;
                    colData[j]++;
                }
            }
        }

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j] == 1){
                    if(rowData[i] > 1 || colData[j] > 1){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};