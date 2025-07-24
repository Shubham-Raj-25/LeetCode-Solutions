#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> tree(n);
        for (auto& e : edges) {
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }

        // subtree_xor[i] = XOR of all nodes in subtree rooted at i
        vector<int> subtree_xor(n);
        vector<int> in(n), out(n), parent(n, -1);
        int time = 0;
        function<void(int, int)> dfs = [&](int u, int par) {
            in[u] = time++;
            subtree_xor[u] = nums[u];
            for (int v : tree[u]) {
                if (v == par) continue;
                parent[v] = u;
                dfs(v, u);
                subtree_xor[u] ^= subtree_xor[v];
            }
            out[u] = time++;
        };
        dfs(0, -1);

        int res = INT_MAX;
        // For all pairs of edges (i, j), where i != j
        // Remove edges between u-parent[u] and v-parent[v]
        // Try all possible pairs of non-overlapping subtrees
        for (int u = 1; u < n; ++u) {
            for (int v = u + 1; v < n; ++v) {
                // Check subtree relationships: Is v in u's subtree, or u in v's, or disjoint?
                bool u_in_v = (in[u] > in[v] && out[u] < out[v]);
                bool v_in_u = (in[v] > in[u] && out[v] < out[u]);
                int a, b, c;
                if (u_in_v) {
                    // u is in v's subtree
                    a = subtree_xor[u];
                    b = subtree_xor[v] ^ subtree_xor[u];
                    c = subtree_xor[0] ^ subtree_xor[v];
                } else if (v_in_u) {
                    // v is in u's subtree
                    a = subtree_xor[v];
                    b = subtree_xor[u] ^ subtree_xor[v];
                    c = subtree_xor[0] ^ subtree_xor[u];
                } else {
                    // Disjoint
                    a = subtree_xor[u];
                    b = subtree_xor[v];
                    c = subtree_xor[0] ^ subtree_xor[u] ^ subtree_xor[v];
                }
                int mx = max({a, b, c});
                int mn = min({a, b, c});
                res = min(res, mx - mn);
            }
        }
        return res;
    }
};