class Solution {
public:
    vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

    int maximumSafenessFactor(vector<vector<int>>& grid) {

        int n = grid.size();

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    dist[i][j]=0;
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){

            auto [x,y]=q.front();
            q.pop();

            for(auto &d:dirs){

                int nx=x+d[0];
                int ny=y+d[1];

                if(nx<0||ny<0||nx>=n||ny>=n)
                    continue;

                if(dist[nx][ny]!=INT_MAX)
                    continue;

                dist[nx][ny]=dist[x][y]+1;
                q.push({nx,ny});
            }
        }

        auto canReach = [&](int safe){

            if(dist[0][0]<safe)
                return false;

            queue<pair<int,int>> q;
            vector<vector<int>> vis(n, vector<int>(n,0));

            q.push({0,0});
            vis[0][0]=1;

            while(!q.empty()){

                auto [x,y]=q.front();
                q.pop();

                if(x==n-1 && y==n-1)
                    return true;

                for(auto &d:dirs){

                    int nx=x+d[0];
                    int ny=y+d[1];

                    if(nx<0||ny<0||nx>=n||ny>=n)
                        continue;

                    if(vis[nx][ny])
                        continue;

                    if(dist[nx][ny]<safe)
                        continue;

                    vis[nx][ny]=1;
                    q.push({nx,ny});
                }
            }

            return false;
        };

        int low=0, high=n*n;

        while(low<=high){

            int mid=(low+high)/2;

            if(canReach(mid))
                low=mid+1;
            else
                high=mid-1;
        }

        return high;
    }
};