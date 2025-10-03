class Solution {
public:
   int trapRainWater(vector<vector<int>>& hM) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> minHeap;
        int n = hM.size();
        int m = hM[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false)); //initialize visited with default value of false

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0||j==0||i==n-1||j==m-1){
                    minHeap.push({hM[i][j],{i,j}});
                    visited[i][j] = true;
                }
            }
        }

        int trappedWater=0;

        int dr[4] = {0,1,0,-1};
        int dc[4] = {-1,0,1,0};

        while(!minHeap.empty()){
            auto it = minHeap.top();
            minHeap.pop();
            int h = it.first;
            int r = it.second.first;
            int c = it.second.second;

            // checking the neighbours

            for(int i=0;i<4;i++){
                int nr = r+dr[i];
                int nc = c+dc[i];

                if(nr>=0 && nc>=0 && nr<n && nc<m && visited[nr][nc]==false){
                    visited[nr][nc] = true;
                    trappedWater += max(0,h-hM[nr][nc]);
                    minHeap.push({max(h,hM[nr][nc]),{nr,nc}});
                }
            }
        }

        return trappedWater;
    }
};