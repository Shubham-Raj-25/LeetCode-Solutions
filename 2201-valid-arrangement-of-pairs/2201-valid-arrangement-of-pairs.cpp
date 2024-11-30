class Solution {
public:
    map<int,vector<int>> adj;
    unordered_map<int,int> indegree, outdegree;
    set<int> nodes;
    vector<int> euler_path;

    void find_euler_path(int curr_node){
        while(outdegree[curr_node]){
            int nei_node = adj[curr_node][outdegree[curr_node]-1];
            outdegree[curr_node]--;
            find_euler_path(nei_node);
        }
        euler_path.push_back(curr_node);
    }

    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        for(auto pair : pairs){
            int u = pair[0], v = pair[1];
            adj[u].push_back(v);
            outdegree[u]++, indegree[v]++;
            nodes.insert(u);
            nodes.insert(v);
        }

        int start_node = -1;

        for(int node : nodes)
            if(outdegree[node]-indegree[node] == 1){
                start_node = node;
                break;
            }

        if(start_node == -1) // we can start at any point
            start_node = pairs[0][0];
        
        find_euler_path(start_node);

        reverse(euler_path.begin(),euler_path.end());

        vector<vector<int>> ans;

        for(int i=0;i<euler_path.size()-1;i++)
            ans.push_back({euler_path[i],euler_path[i+1]});
        
        return ans;
    }
};