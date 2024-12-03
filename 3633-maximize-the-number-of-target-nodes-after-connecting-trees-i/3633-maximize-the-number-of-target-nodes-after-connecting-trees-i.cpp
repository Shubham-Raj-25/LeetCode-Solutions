class Solution {
public:
    vector<int> helper(vector<vector<int>>& adj, int k){
        int m = adj.size();
        vector<int> res(m,0);

        for(int i=0;i<m;i++){
            int _k = k;
            queue<int> q;
            q.push(i);
            unordered_set<int> vis;
            while(q.size() && _k){
                
                int size = q.size();
                
                while(size--){
                    int curr = q.front();
                    q.pop();
                    if(vis.count(curr))
                        continue;
                    vis.insert(curr);
                    res[i]++;
                    for(int nei : adj[curr])
                        q.push(nei);
                }

                _k--;
            }
        }

        return res;

    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        // in second graph find out maximum possible for each node
        // get the absolute maximum out of them 
        // in first graph find out maximum posisble for each node
        // add 3 + 2
        int n = edges1.size()+1;
        int m = edges2.size()+1;
        vector<vector<int>> adj1(n), adj2(m);

        for(auto edge : edges1){
            adj1[edge[0]].push_back(edge[1]);
            adj1[edge[1]].push_back(edge[0]);
        }

        for(auto edge : edges2){
            adj2[edge[0]].push_back(edge[1]);
            adj2[edge[1]].push_back(edge[0]);
        }

        vector<int> maxTarget1 = helper(adj1,k+1);
        
        vector<int> maxTarget2 = helper(adj2,k);
        
        int maxi = 0;
        for(int it : maxTarget2)
            maxi = max(maxi, it);

        for(int i=0;i<n;i++)
            maxTarget1[i] += maxi;

        return maxTarget1;
    }
};