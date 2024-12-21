class Solution {
public:
    int dfs(int curr, int prev, vector<vector<int>>& adj, vector<int>& values, int k, int& maxComp){
        
        int curr_sum = values[curr];
        
        for(int nei : adj[curr]){
            if(nei != prev){
                curr_sum += dfs(nei,curr,adj,values,k,maxComp) % k;
            }
        }
        
        if(curr_sum % k == 0){
            maxComp += 1;
            return 0;
        }

        return curr_sum;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        vector<bool> vis(n,false);
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int maxComp = 0;

        dfs(0,-1,adj,values,k,maxComp);

        return maxComp;
    }
};