class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int,int>>> adj(n);
        vector<bool> vis(n,false);
        vector<vector<int>> edges;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int minCost;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1]-points[j][1]);
                adj[i].push_back({j,dist});
                adj[j].push_back({i,dist});
            }
        }

        pq.push({0,0});
        minCost = 0;

        while(pq.size()){
            auto [cost,curr] = pq.top();
            pq.pop();
            
            if(vis[curr])
                continue;
            
            vis[curr] = true;
            minCost += cost;

            for(auto it : adj[curr]){
                if(!vis[it.first])
                    pq.push({it.second,it.first});
            }
        }

        return minCost;

    }
};