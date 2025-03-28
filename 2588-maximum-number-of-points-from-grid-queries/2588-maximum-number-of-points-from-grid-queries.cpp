class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int n = grid.size(), m = grid[0].size();
        vector<int> ans(queries.size(), 0);
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        
        vector<int> temp = queries;
        sort(temp.begin(), temp.end());

        map<int, int> mp; 
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        pq.push({grid[0][0], {0, 0}});
        
        int points = 0;
        for (int q : temp) {
            while (!pq.empty() && pq.top().first < q) {
                auto [val, pos] = pq.top();
                pq.pop();
                int i = pos.first, j = pos.second;

                if (vis[i][j]) continue;
                vis[i][j] = 1;
                points++;

                for (int k = 0; k < 4; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];

                    if (ni >= 0 && ni < n && nj >= 0 && nj < m && !vis[ni][nj]) {
                        pq.push({grid[ni][nj], {ni, nj}});
                    }
                }
            }
            mp[q] = points;
        }
        
        for (int i = 0; i < queries.size(); i++) {
            ans[i] = mp[queries[i]];
        }
        return ans;
    }
};