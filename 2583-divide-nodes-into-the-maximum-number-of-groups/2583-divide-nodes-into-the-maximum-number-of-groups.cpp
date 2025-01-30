class Solution {
private:
    void dfs(int curr, int comp, vector<vector<int>>& adj, vector<int>& nodesToComp, vector<vector<int>>& components) {
        if (nodesToComp[curr] != -1) return;
        nodesToComp[curr] = comp;
        components[comp].push_back(curr);
        for (int nei : adj[curr]) {
            if (nodesToComp[nei] == -1) {
                dfs(nei, comp, adj, nodesToComp, components);
            }
        }
    }

    int bfs(int startNode, vector<vector<int>>& adj, int n) {
        vector<int> level(n, -1);
        queue<int> q;
        q.push(startNode);
        level[startNode] = 1;
        int maxLevel = 1;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (int nei : adj[curr]) {
                if (level[nei] == -1) {
                    level[nei] = level[curr] + 1;
                    maxLevel = max(maxLevel, level[nei]);
                    q.push(nei);
                } else if (abs(level[nei] - level[curr]) != 1) {
                    return -1;  
                }
            }
        }
        return maxLevel;
    }

public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<int> nodesToComp(n, -1);
        vector<vector<int>> adj(n), components(n);

        for (vector<int>& edge : edges) {
            adj[edge[0] - 1].push_back(edge[1] - 1);
            adj[edge[1] - 1].push_back(edge[0] - 1);
        }

        int comp = 0, maxGroups = 0;
        for (int i = 0; i < n; i++) {
            if (nodesToComp[i] == -1) {
                dfs(i, comp, adj, nodesToComp, components);
                comp++;
            }
        }

        for (int i = 0; i < comp; i++) {
            int bestGroups = -1;
            for (int startNode : components[i]) {
                int result = bfs(startNode, adj, n);
                if (result != -1) {
                    bestGroups = max(bestGroups, result);
                }
            }
            if (bestGroups == -1) return -1;
            maxGroups += bestGroups;
        }

        return maxGroups;
    }
};
