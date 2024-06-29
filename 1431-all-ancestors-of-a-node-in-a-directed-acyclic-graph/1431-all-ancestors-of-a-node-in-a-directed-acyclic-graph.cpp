class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n), ans(n);
        
        for(auto edge : edges)
            adj[edge[0]].push_back(edge[1]);
        
        for(int par=0;par<n;par++){
            queue<int> q;
            vector<int> vis(n,0);
            q.push(par);
            while(q.size()){
                int curr = q.front();
                q.pop();
                
                if(curr != par && !vis[curr])
                    ans[curr].push_back(par);
                
                vis[curr] = 1;

                for(int nei : adj[curr])
                    if(!vis[nei])
                        q.push(nei);
            }
        }

        return ans;
    }
};