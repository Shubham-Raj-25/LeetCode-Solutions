class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ans;
        int directions[5] = {0,1,0,-1,0};
        int steps = 1;
        int dir = 0; // curr dir
        int r = rStart, c = cStart;
        ans.push_back({r,c});
        while(ans.size() < rows * cols ){
            for(int i=0;i<2;i++){
                for(int j=0;j<steps;j++){
                    r += directions[dir];
                    c += directions[dir+1];
                    if(r >= 0 && r<rows && c>=0 && c<cols)
                        ans.push_back({r,c});
                }
                dir = (dir+1)%4;
            }
            steps++;
        }

        return ans;
    }
};