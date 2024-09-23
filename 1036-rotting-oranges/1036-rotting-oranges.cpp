class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int time = 0, fresh_oranges = 0;
        
        queue<pair<int,int>> q;
        
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 2)
                    q.push({i,j});
                else if(grid[i][j] == 1)
                    fresh_oranges++;
            }
        
        if(fresh_oranges == 0)
            return 0;
            
        int dx[4] = {1,0,-1,0};
        int dy[4] = {0,-1,0,1};

        while(q.size()){
            int size = q.size();
            time++;
            for(int i=0;i<size;i++){
                int curr_x = q.front().first;
                int curr_y = q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    int new_x = curr_x + dx[k];
                    int new_y = curr_y + dy[k];
                    if(new_x>=0 && new_y>=0 && new_x<grid.size() && new_y<grid[0].size() && grid[new_x][new_y]==1){
                        grid[new_x][new_y] = 2;
                        fresh_oranges--;
                        q.push({new_x,new_y});
                    }
                }
            }
        }

        return fresh_oranges == 0 ? time -1 : -1;

    }
};