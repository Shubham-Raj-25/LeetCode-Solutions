class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<pair<int,int>,int>>q;
        int m = maze.size();
        int n = maze[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int dr[4] = {1,0,-1,0};
        int dc[4] = {0,-1,0,1};
        
        q.push({{entrance[0],entrance[1]},0});
        vis[entrance[0]][entrance[1]] = 1;

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int dist = q.front().second;

            q.pop();

            if(maze[r][c]=='.' && (r==0 || c==0 || r==m-1 || c==n-1) && (r!=entrance[0] || c!=entrance[1]))
                return dist;
            
            for(int i=0;i<4;i++){
                int nr = r+dr[i];
                int nc = c+dc[i];
                if(nr<0 || nc<0 || nr==m || nc==n || vis[nr][nc] || maze[nr][nc]=='+')
                    continue;
                
                vis[nr][nc]=1;
                cout << nr << " " << nc << endl;
                q.push({{nr,nc},dist+1});
            }
        }

        return -1;
    }
};