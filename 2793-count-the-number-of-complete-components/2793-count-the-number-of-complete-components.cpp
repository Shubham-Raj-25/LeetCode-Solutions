class Solution {
public:
    void dfs(int node,vector<vector<int>>& adj,vector<bool>& vis,int& noNodes,int& noEdges){
        vis[node] = true;
        noNodes++;
        noEdges += adj[node].size();
        for(auto nei:adj[node]){
            if(!vis[nei])
                dfs(nei,adj,vis,noNodes,noEdges);
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }        
        vector<bool> vis(n,false);
        int ans =0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                int noNodes =0, noEdges = 0;
                dfs(i,adj,vis,noNodes,noEdges);
                if(noNodes*(noNodes-1)==noEdges) ans++;
            }
        }

        return ans;
    }
};