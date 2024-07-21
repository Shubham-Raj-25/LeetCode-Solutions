class Solution {
    vector<int> topoSort (vector<vector<int>> g) {
        int n = g.size();
        
        vector<int> in(n, 0);
        for (int i = 0; i < n; i ++) {
            for (auto child: g[i]) 
                in[child] ++;
        }
        
        vector<int> result;
        queue<int> q;
        for (int j = 0; j < n; j ++)
            if (in[j] == 0) q.push(j);
        
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            result.push_back(cur);
            
            for (auto child: g[cur]) {
                in[child] --;
                if (in[child] == 0) q.push(child);
            }
        }
        
        return result;
    }
    
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> result (k, vector<int>(k, 0));
        
        vector<vector<int>> graph(k);
        for (auto i : rowConditions) graph[i[0]-1].push_back(i[1]-1);
        vector<int> top_down = topoSort (graph);
        
        for (int j = 0; j < k; j ++) graph[j].clear();
        for (auto i : colConditions) graph[i[0]-1].push_back(i[1]-1);
        vector<int> left_right = topoSort (graph);
        
        if (top_down.size() != k || left_right.size() != k) return {};
        
        vector<int> pos_left_right(k);
        for (int j = 0; j < k; j ++) pos_left_right[left_right[j]] = j;
        
        for (int j = 0; j < k; j ++) {
            int cur = top_down[j];
            result[j][pos_left_right[cur]] = cur+1;
        }
        
        return result;
    }
};