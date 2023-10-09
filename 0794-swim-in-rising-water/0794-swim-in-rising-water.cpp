class DisjointSet {
public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    bool dfs(vector<vector<int>>& grid,vector<vector<int>>& vis,int i,int j,int time){
        int n = grid.size();
        int dir[5] = {-1,0,1,0,-1};
        if(i < 0 || j < 0 || i >= n || j>= n || vis[i][j] || grid[i][j] > time)return false;
        if(i == n-1 && j == n-1)return true;
        vis[i][j] = true;
        for(int k = 0; k <4; k++){
            if(dfs(grid,vis,i + dir[k], j + dir[k+1],time))return true;
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> vis(n,vector<int>(n));
        int l= max({2*(n-1), grid[0][0], grid[n-1][n-1]});
        int r = n*n -1;
        // for(int time = minReq; time < n*n; time++){
        //     if(dfs(grid,vis,0,0,time)) return time;
        //     for_each(begin(vis), end(vis),[](auto& v) {
        //         fill(begin(v),end(v),0);
        //     });
        // }        
        while(l <= r){
            int mid = (l + r) /2;
            if(dfs(grid,vis,0,0,mid))r = mid-1;
            else {
                l = mid+1;
            }
            for_each(begin(vis), end(vis),[](auto& v) {
                fill(begin(v),end(v),0);
            });
        }
        return l;
    }

    int UnionFind(vector<vector<int>>& grid){
        int n= grid.size();
        DisjointSet ds(n*n);
        pair<int,int> locations[n*n];
        vector<vector<int>> vis(n,vector<int>(n,-1));

        for(int i=0;i < n;i++){
            for(int j = 0; j < n; j++){
                locations[grid[i][j]] = {i,j};
            }
        }

        int dir[5] ={-1,0,1,0,-1};

        for(int time  =0; time < n*n; time++){
            int x = locations[time].first;
            int y = locations[time].second;
            vis[x][y] = 1;

            for(int k =0; k < 4;k++){
                int nr = x + dir[k];
                int nc = y + dir[k+1];

                if(nr >=0 && nr < n && nc >=0 && nc < n && vis[nr][nc] == 1){
                    ds.unionBySize(x*n + y , nr*n + nc);
                }
            }

            if(ds.findUPar(0) == ds.findUPar(n*n -1)){return time;}

        }

        return n*n - 1;
    }
};