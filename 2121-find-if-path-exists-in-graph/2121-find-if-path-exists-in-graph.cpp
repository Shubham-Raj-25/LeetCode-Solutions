class Solution {
public:
    bool dfs(vector<vector<int>>& adj, int s, int d, vector<bool>& vis){
        if(s==d)
            return true;
        
        bool ans = false;

        for(auto it:adj[s]){
            if(!vis[it]){
                vis[it] = true;
                ans = ans || dfs(adj,it,d,vis);        
            }
        }

        return ans;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<bool> vis(n,false);
        vis[source] = true;

        return dfs(adj,source,destination,vis);
    }
};