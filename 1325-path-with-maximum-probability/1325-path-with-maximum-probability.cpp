class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        // normal queue with a prob array just like dist array?
        vector<double> prob(n,0);
        vector<vector<pair<int,double>>> adj(n);
        queue<int> q;

        for(int i=0;i<edges.size();i++){
            auto edge = edges[i];
            adj[edge[0]].push_back({edge[1],succProb[i]});
            adj[edge[1]].push_back({edge[0],succProb[i]});
        }

        prob[start_node] = 1;

        q.push({start_node});

        while(q.size()){
            int curr_node = q.front();
            q.pop();

            for(auto nei_data : adj[curr_node]){
                int nei_node = nei_data.first;
                double nei_prob = nei_data.second;
                if(prob[curr_node] * nei_prob > prob[nei_node]){
                    prob[nei_node] = prob[curr_node] * nei_prob;
                    q.push(nei_node);
                }
            }
        }
        return prob[end_node];
    }
};