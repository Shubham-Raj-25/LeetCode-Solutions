class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0});
        int n = points.size();
        vector<bool> vis(n,false);
        int weight = 0;

        while(n){
            int wt = pq.top().first;
            int curr = pq.top().second;
            pq.pop();

            if(vis[curr]) continue;
            n--;
            vis[curr] = true;
            weight += wt;

            for(int i=0;i<points.size();i++){
                if(!vis[i]){
                    int dist = abs(points[curr][1]-points[i][1])+abs(points[curr][0]-points[i][0]);
                    pq.push({dist,i});
                    }
                
            }

        }

        return weight;
    }
};