class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<bool>> vis(rows, vector<bool>(cols, false));
        pq.push({0,{0,0}});
        int dx[4] = {0,1,0,-1};
        int dy[4] = {-1,0,1,0};

        if(grid[0][1] > 1 && grid[1][0] > 1)
            return -1;

        while(pq.size()){
            int curr_time = pq.top().first;
            int cx = pq.top().second.first, cy = pq.top().second.second;
            pq.pop();
            
            if(cx == rows - 1 && cy == cols - 1)
                return curr_time;
            
            if(vis[cx][cy])
                    continue;
            vis[cx][cy] = true;

            for(int d=0; d<4; d++){
                int nx = cx + dx[d];
                int ny = cy + dy[d];
                if(nx>=0 && nx<rows && ny>=0 && ny<cols && !vis[nx][ny]){
                    int wait_time = (grid[nx][ny] - curr_time) % 2 == 0;
                    pq.push({max(grid[nx][ny]+wait_time,curr_time+1),{nx,ny}});
                }
            }
        }

        return -1;
    }
};