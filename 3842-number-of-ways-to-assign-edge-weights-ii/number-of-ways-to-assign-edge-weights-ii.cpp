#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
    int LOG = 20; // 2^20 is enough for N = 10^5
    vector<int> depth;
    vector<vector<int>> up;

    // Precompute depths and Binary Lifting table
    void dfs(int node, int parent, int d, const vector<vector<int>>& adj) {
        depth[node] = d;
        up[node][0] = parent;
        
        for (int i = 1; i < LOG; i++) {
            if (up[node][i - 1] != -1) {
                up[node][i] = up[up[node][i - 1]][i - 1];
            } else {
                up[node][i] = -1;
            }
        }

        for (int neighbor : adj[node]) {
            if (neighbor != parent) {
                dfs(neighbor, node, d + 1, adj);
            }
        }
    }

    // Binary Lifting to find the Lowest Common Ancestor
    int getLCA(int u, int v) {
        // Ensure u is deeper than v
        if (depth[u] < depth[v]) swap(u, v);

        // Bring u and v to the same depth
        int diff = depth[u] - depth[v];
        for (int i = 0; i < LOG; i++) {
            if ((diff >> i) & 1) {
                u = up[u][i];
            }
        }

        if (u == v) return u;

        // Move both nodes upwards together
        for (int i = LOG - 1; i >= 0; i--) {
            if (up[u][i] != -1 && up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }

        return up[u][0]; // The parent of the final step is the LCA
    }

    // Modular Exponentiation
    long long binaryExp(long long base, int exp, int mod) {
        long long res = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }

public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1;
        depth.assign(n + 1, 0);
        up.assign(n + 1, vector<int>(LOG, -1));

        // Build adjacency list
        vector<vector<int>> adj(n + 1);
        for (const auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        // Step 1: Precompute Tree structure from Node 1
        dfs(1, -1, 0, adj);

        int MOD = 1e9 + 7;
        vector<int> ans;
        ans.reserve(queries.size());

        // Step 2: Answer queries
        for (const auto& q : queries) {
            int u = q[0], v = q[1];
            
            if (u == v) {
                ans.push_back(0);
                continue;
            }
            
            int lca = getLCA(u, v);
            int dist = depth[u] + depth[v] - 2 * depth[lca];
            
            ans.push_back(binaryExp(2, dist - 1, MOD));
        }

        return ans;
    }
};