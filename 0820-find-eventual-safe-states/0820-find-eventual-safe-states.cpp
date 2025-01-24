class Solution {
public:
    bool dfs(int i, vector<vector<int>>& graph, vector<bool>& isSafe, vector<bool>& vis){
        if(isSafe[i]){
            return true;
        }
        if(vis[i]){
            return false;
        }
        
        vis[i] = true;

        bool isCurrSafe = true;
        for(auto nei : graph[i]){
            isCurrSafe &= dfs(nei, graph,isSafe,vis);
        }
        return isSafe[i] = isCurrSafe;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        
        vector<bool> isSafe(n,false), vis(n,false);
        vector<int> ans;

        for(int i=0;i<n;i++){
            if(graph[i].size() == 0){
                isSafe[i] = true;
            }
        }

        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,graph,isSafe,vis);
            }
        }

        for(int i=0;i<n;i++){
            if(isSafe[i]){
                ans.push_back(i);
            }
        }

        return ans;
    }
};