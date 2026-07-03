#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) 
    {
        int n = online.size();
        
        vector<vector<pair<int, int>>> adj(n);
        vector<int> inDegree(n, 0);
        int max_cost = 0;
        
        for (const auto& e : edges) 
        {
            int u = e[0], v = e[1], cost = e[2];
            adj[u].push_back({v, cost});
            inDegree[v]++;
            max_cost = max(max_cost, cost);
        }
        
        vector<int> topo;
        topo.reserve(n);
        queue<int> q;
        
        for (int i = 0; i < n; ++i) 
        {
            if (inDegree[i] == 0) 
            {
                q.push(i);
            }
        }
        
        while (!q.empty()) 
        {
            int u = q.front();
            q.pop();
            topo.push_back(u);
            for (const auto& edge : adj[u]) 
            {
                int v = edge.first;
                if (--inDegree[v] == 0) 
                {
                    q.push(v);
                }
            }
        }
        
        auto isValid = [&](int mid) 
        {
            const long long INF = 1e18; 
            vector<long long> dp(n, INF);
            dp[0] = 0;
            
            for (int u : topo) 
            {
                if (dp[u] == INF) continue;
                if (!online[u]) continue; 
                
                for (const auto& edge : adj[u]) 
                {
                    int v = edge.first;
                    int cost = edge.second;
                    
                    if (cost >= mid) 
                    {
                        dp[v] = min(dp[v], dp[u] + cost);
                    }
                }
            }
            return dp[n - 1] <= k;
        };
        
        int left = 0, right = max_cost;
        int ans = -1;
        
        while (left <= right) 
        {
            int mid = left + (right - left) / 2;
            if (isValid(mid)) 
            {
                ans = mid;       
                left = mid + 1;  
            } 
            else 
            {
                right = mid - 1; 
            }
        }
        return ans;
    }
};