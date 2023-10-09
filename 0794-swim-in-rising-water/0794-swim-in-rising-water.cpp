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
    int swimInWater(vector<vector<int>>& grid) {
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