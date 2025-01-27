class Solution {
public:
    bool canReach(int from, int to, vector<vector<int>>& adj, vector<bool>& vis){
        if(from == to){
            return true;
        }
        if(vis[from]){
            return false;
        }
        vis[from] = true;

        for(auto nei : adj[from]){
            if(!vis[nei] && canReach(nei,to,adj,vis)){
                return true;
            }
        }
        
        return false;
    }
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // for every query traverse the graph to see if you can reach from u -> v ?
        vector<vector<int>> adj(n);
        vector<bool> ans;
        for(auto it: prerequisites){
            adj[it[0]].push_back(it[1]);
        }
        for(auto query : queries){
            vector<bool> vis(n);
            ans.push_back(canReach(query[0],query[1],adj,vis)); 
        }

        return ans;
    }
};