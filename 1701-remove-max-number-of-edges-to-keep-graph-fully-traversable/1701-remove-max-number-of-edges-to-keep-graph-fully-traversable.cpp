class DisjointSet {

    vector<int> rank,parent,size;
    int components;
    public:
    DisjointSet(int n){
      rank.resize(n+1, 0);
      parent.resize(n+1);
      size.resize(n+1);
      components=n;

      for(int i=0; i <= n; i++){
        parent[i] = i;
        size[i] = 1;
      }
    }

    int findParent(int node){
      if(parent[node] == node){
        return node;
      }
      return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v){
      int ulp_u = findParent(u);
      int ulp_v = findParent(v);
      if(ulp_u == ulp_v)return;
      if(rank[ulp_u] < rank[ulp_v]){
        parent[ulp_u] = ulp_v;
      }
      else if(rank[ulp_v] < rank[ulp_u]){
        parent[ulp_v] = ulp_u;
      }
      else{
        parent[ulp_v] = ulp_u;
        rank[ulp_u]++;
      }
      components--;
    }

    bool isSingleComponent(){
        return components==1;
    }

};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
       
        DisjointSet a(n),b(n);

        auto lambda = [](vector<int>& a, vector<int>& b){
            return a[0] > b[0];
        };

        sort(begin(edges),end(edges),lambda);

        int edgeCount =0;

        for(auto& vec: edges){
            int type = vec[0];
            int u = vec[1];
            int v = vec[2];

            if(type == 3){
                bool addedNewEdge = false;
                if(a.findParent(u) != a.findParent(v)){
                    a.unionByRank(u,v);
                    addedNewEdge = true;
                }
                if(b.findParent(u) != b.findParent(v)){
                    b.unionByRank(u,v);
                    addedNewEdge = true;
                }

                if(addedNewEdge){
                    edgeCount++;
                }
            }else if(type == 1){
               
                if(a.findParent(u) != a.findParent(v)){
                    a.unionByRank(u,v);
                    edgeCount++;
                }
            }
            else{
            
                if(b.findParent(u) != b.findParent(v)){
                    b.unionByRank(u,v);
                    edgeCount++;
                }
            }
        }

        if(a.isSingleComponent() && b.isSingleComponent()){
            return edges.size() - edgeCount;
        }
        return -1;
    }
};