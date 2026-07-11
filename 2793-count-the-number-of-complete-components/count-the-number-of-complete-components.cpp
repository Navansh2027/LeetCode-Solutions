class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) \
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        int completeComponentsCount = 0;

        auto dfs = [&](auto& self, int node, int& vertexCount, int& degreeSum) -> void 
        {
            visited[node] = true;
            vertexCount++;
            degreeSum += adj[node].size();

            for (int neighbor : adj[node]) 
            {
                if (!visited[neighbor]) 
                {
                    self(self, neighbor, vertexCount, degreeSum);
                }
            }
        };

        for (int i = 0; i < n; ++i) 
        {
            if (!visited[i]) 
            {
                int vertexCount = 0;
                int degreeSum = 0;

                dfs(dfs, i, vertexCount, degreeSum);

                if (degreeSum == vertexCount * (vertexCount - 1)) 
                {
                    completeComponentsCount++;
                }
            }
        }

        return completeComponentsCount;
    }
};