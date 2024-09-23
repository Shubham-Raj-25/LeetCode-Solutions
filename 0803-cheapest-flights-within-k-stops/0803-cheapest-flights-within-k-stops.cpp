class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto flight : flights)
            adj[flight[0]].push_back({flight[1],flight[2]});
        
        vector<int> cost_from_src(n, INT_MAX);

        cost_from_src[src] = 0;

        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({0,0,src});

        while(pq.size()){
            int no_of_stops = pq.top()[0];
            int curr_cost = pq.top()[1];
            int curr_stop = pq.top()[2];
            pq.pop();

            if(no_of_stops > k)
                continue;
            
            for(auto nei : adj[curr_stop]){
                int nei_stop = nei.first;
                int nei_cost = nei.second;
                if(cost_from_src[nei_stop] > curr_cost + nei_cost){
                    cost_from_src[nei_stop] = curr_cost + nei_cost;
                    pq.push({no_of_stops+1,cost_from_src[nei_stop],nei_stop});
                }
            }
        }

        return cost_from_src[dst] == INT_MAX ? -1 : cost_from_src[dst];

    }
};