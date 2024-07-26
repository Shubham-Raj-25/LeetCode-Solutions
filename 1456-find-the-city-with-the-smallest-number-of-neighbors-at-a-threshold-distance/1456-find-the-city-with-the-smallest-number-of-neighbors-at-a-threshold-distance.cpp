class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int, int>>> adj(n);
        
        for (auto edge : edges) {
            adj[edge[0]].emplace_back(edge[1], edge[2]);
            adj[edge[1]].emplace_back(edge[0], edge[2]);
        }

        auto dijkstra = [&](int src) {
            vector<int> dist(n, INT_MAX);
            dist[src] = 0;
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            pq.emplace(0, src);

            while (!pq.empty()) {
                int currDist = pq.top().first;
                int curr = pq.top().second;
                pq.pop();

                if (currDist > dist[curr]) continue;

                for (auto &neighbor : adj[curr]) {
                    int next = neighbor.first;
                    int weight = neighbor.second;
                    if (dist[curr] + weight <= distanceThreshold && dist[curr] + weight < dist[next]) {
                        dist[next] = dist[curr] + weight;
                        pq.emplace(dist[next], next);
                    }
                }
            }

            return dist;
        };

        int minReachableCities = INT_MAX;
        int bestCity = -1;

        for (int i = 0; i < n; ++i) {
            vector<int> distances = dijkstra(i);
            int reachableCities = 0;
            for (int j = 0; j < n; ++j) {
                if (i != j && distances[j] <= distanceThreshold) {
                    ++reachableCities;
                }
            }
            if (reachableCities <= minReachableCities) {
                minReachableCities = reachableCities;
                bestCity = i;
            }
        }

        return bestCity;
    }
};
