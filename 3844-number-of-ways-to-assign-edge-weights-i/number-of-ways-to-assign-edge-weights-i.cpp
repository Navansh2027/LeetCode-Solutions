#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Fixed: Reverted to a single parameter to match LeetCode's exact template
    int assignEdgeWeights(vector<vector<int>>& edges) {
        
        // Fixed: Calculate n internally based on the number of edges
        int n = edges.size() + 1;
        
        vector<vector<int>> adj(n + 1);
        for(const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int max_depth = 0; 
        queue<pair<int, int>> q;
        vector<bool> visited(n + 1, false);

        q.push({1, 0});
        visited[1] = true;

        while(!q.empty()) {
            auto [node, depth] = q.front();
            q.pop();

            max_depth = max(max_depth, depth); 

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push({neighbor, depth + 1});
                }
            }
        }

        if (max_depth == 0) return 0;

        int MOD = 1e9 + 7;
        return binaryExp(2, max_depth - 1, MOD);
    }

private:
    long long binaryExp(long long base, int exp, int mod) {
        long long result = 1;
        base = base % mod;

        while(exp > 0) {
            if(exp % 2 == 1) {
                result = (result * base) % mod;
            }

            base = (base * base) % mod;
            exp /= 2;
        }

        return result;
    }    
};