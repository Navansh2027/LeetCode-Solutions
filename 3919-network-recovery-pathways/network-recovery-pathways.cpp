#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        // Deduce 'n' from the size of the online array
        int n = online.size();
        
        // Step 1: Build the adjacency list and calculate in-degrees
        vector<vector<pair<int, int>>> adj(n);
        vector<int> inDegree(n, 0);
        int max_cost = 0;
        
        for (const auto& e : edges) {
            int u = e[0], v = e[1], cost = e[2];
            adj[u].push_back({v, cost});
            inDegree[v]++;
            max_cost = max(max_cost, cost);
        }
        
        // Step 2: Compute Topological Sort using Kahn's Algorithm
        vector<int> topo;
        topo.reserve(n);
        queue<int> q;
        
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topo.push_back(u);
            for (const auto& edge : adj[u]) {
                int v = edge.first;
                if (--inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        
        // Step 3: Helper lambda to check if a valid path exists for a given `mid`
        auto isValid = [&](int mid) {
            const long long INF = 1e18; 
            vector<long long> dp(n, INF);
            dp[0] = 0;
            
            for (int u : topo) {
                // If the node is unreachable or offline, skip it
                if (dp[u] == INF) continue;
                if (!online[u]) continue; 
                
                // Relax outgoing edges
                for (const auto& edge : adj[u]) {
                    int v = edge.first;
                    int cost = edge.second;
                    
                    // Only traverse edges that meet our minimum cost requirement
                    if (cost >= mid) {
                        dp[v] = min(dp[v], dp[u] + cost);
                    }
                }
            }
            return dp[n - 1] <= k;
        };
        
        // Step 4: Binary search for the maximum possible minimum-edge cost
        int left = 0, right = max_cost;
        int ans = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isValid(mid)) {
                ans = mid;       // Valid path found, save answer
                left = mid + 1;  // Try to push for a higher minimum edge cost
            } else {
                right = mid - 1; // Cost is too high, lower the requirement
            }
        }
        
        return ans;
    }
};