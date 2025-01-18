class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        vector<vector<int>> vis(r, vector<int>(c,0));
        int dr[4] = {0,0,1,-1};
        int dc[4] = {1,-1,0,0};

        pq.push({0,0,0});

        while(pq.size()){
            auto top = pq.top();
            int currCost = top[0], row = top[1], col = top[2];
            pq.pop();
            if(vis[row][col]){
                continue;
            }
            vis[row][col] = 1;

            if(row == r-1 && col == c-1){
                return currCost;
            }

            for(int dir = 0; dir <4; dir++){
                int nr = row + dr[dir];
                int nc = col + dc[dir];
                if(nr>=0 && nr <r && nc>=0 && nc<c && !vis[nr][nc]){
                    int extraCost = dir+1 != grid[row][col];
                    pq.push({currCost + extraCost, nr,nc});
                }
            }
        }

        return -1;        
    }
};