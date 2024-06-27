class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int> degree;
        
        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            degree[u]++;
            degree[v]++;
            if(degree[u] > 1)
                return u;
            if(degree[v] > 1)
                return v;
        }

        return -1;
    }
};