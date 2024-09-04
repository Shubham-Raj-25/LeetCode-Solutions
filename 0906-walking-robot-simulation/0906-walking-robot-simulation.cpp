class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int ans = 0;
        set<pair<int, int>> obs;
        vector<vector<int>> dir = {{0,1}, {1,0},{0,-1},{-1,0}};  // North, East, South, West
        int curr_dir = 0, curr_x = 0, curr_y = 0;
        
        for(auto it : obstacles)
            obs.insert({it[0], it[1]});
        
        for(int cmd : commands){
            if(cmd == -2)
                curr_dir = (curr_dir + 3) % 4;  // Turn left
            else if(cmd == -1)
                curr_dir = (curr_dir + 1) % 4;  // Turn right
            else{
                for(int k = 0; k < cmd; k++){
                    int new_x = curr_x + dir[curr_dir][0];
                    int new_y = curr_y + dir[curr_dir][1];
                    if(obs.count({new_x, new_y}))
                        break; 
                    curr_x = new_x;
                    curr_y = new_y;
                    ans = max(ans, curr_x*curr_x + curr_y*curr_y);
                }
            }
        }
        return ans;
    }
};
