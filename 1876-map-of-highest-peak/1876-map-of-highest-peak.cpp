class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        // multisource bfs from water 
        int rows = isWater.size(), cols = isWater[0].size();
        vector<vector<int>> heights(rows, vector<int>(cols,-1));
        queue<pair<int,int>> q;
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(isWater[i][j]){
                    heights[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

        int dr[4] = {0,1,0,-1};
        int dc[4] = {-1,0,1,0};

        while(q.size()){
            int currRow = q.front().first;
            int currCol = q.front().second;
            q.pop();
            int currH = heights[currRow][currCol];

            for(int k=0;k<4;k++){
                int newR = currRow + dr[k];
                int newC = currCol + dc[k];
                if(newR >=0 && newR <rows && newC >=0 && newC <cols && heights[newR][newC] == -1){
                    heights[newR][newC] = currH+1;
                    q.push({newR,newC});
                }
            }
        }

        return heights;
    }
};