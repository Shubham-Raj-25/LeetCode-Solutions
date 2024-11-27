class Solution {
public:
    int minDist(int n,vector<vector<int>>& adj){
        queue<int> q;
        q.push(0);
        int steps = 0;
        unordered_set<int> vis;
        while(q.size()){
            int k = q.size();
            while(k--){
            int curr = q.front();
            q.pop();
            
            if(curr == n-1)
                return steps;
            
            for(int nei : adj[curr]){
                if(!vis.count(nei)){
                    vis.insert(nei);
                    q.push(nei);
                }
            }
            }
            steps++;
        }
        return -1;
    }

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        // brute force
        vector<vector<int>> adj(n);
        vector<int> ans;
        for(int i=0;i<n-1;i++)
            adj[i].push_back(i+1);
        
        for(auto query : queries){
            adj[query[0]].push_back(query[1]);
            ans.push_back(minDist(n,adj));
        }

        return ans;
    }
};