class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        int r = heights.size();
        int c = heights[0].size();

        vector<vector<int>> effort(r,vector<int>(c,1e6));

        pq.push({0,{0,0}});

        effort[0][0] = 0;

        int dr[4] = {0,1,0,-1};
        int dc[4] = {-1,0,1,0};

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int eff = it.first;
            int i = it.second.first;
            int j = it.second.second;

            if(i==r-1 && j==c-1) return eff;

            for(int k=0;k<4;k++){
                int nr = i+dr[k];
                int nc = j+dc[k];

                if(nr>=0 && nc>=0 && nr<r && nc<c){
                    int newEffort = max(eff, abs(heights[nr][nc]-heights[i][j]));
                    if(newEffort < effort[nr][nc]){
                        effort[nr][nc] = newEffort;
                        pq.push({newEffort,{nr,nc}});
                    }
                }
            }
        }

        return 69;

    }
};