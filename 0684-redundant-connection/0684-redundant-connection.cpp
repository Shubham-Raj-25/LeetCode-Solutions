class Solution {
public:
    bool isCycleFree(int currNode, int parNode, vector<unordered_set<int>>& adj, unordered_set<int>& vis){
        if(vis.count(currNode)){
            return false;
        }
        vis.insert(currNode);
        for(int nei : adj[currNode]){
            if(nei != parNode && !isCycleFree(nei,currNode,adj,vis)){
                return false;
            }
        }
        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<unordered_set<int>> adj(n+1);
        for(auto edge : edges){
            adj[edge[0]].insert(edge[1]);
            adj[edge[1]].insert(edge[0]);
        }

        for(int i=n-1;i>=0;i--){
            int u = edges[i][0];
            int v = edges[i][1];
            if(adj[u].size() > 1 && adj[v].size() > 1){
                unordered_set<int> vis;
                adj[u].erase(v);
                adj[v].erase(u);
                if(isCycleFree(1,-1,adj,vis) && vis.size() == n){
                    return edges[i];
                }
                adj[u].insert(v);
                adj[v].insert(u);
            }
        }

        return {-1,-1};
    }
};


/*

         *
         |
    * -- * -- *
         |    |
         *-----


    * -- * -- * -- * -- *         
    |              |    |
    * -- *         ---- *

// do dfs for every non terminal edges from last

*/