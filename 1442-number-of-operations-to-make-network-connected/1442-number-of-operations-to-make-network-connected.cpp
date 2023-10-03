class Disjointset{
    public:
    vector<int> parent,size;
    
    Disjointset(int n){
        size.resize(n+1,1);
        parent.resize(n+1,1);
        
        for(int i=0;i <=n; i++){
            parent[i] = i;
        }
    }
    
    int findUPar(int node){
        if(parent[node] == node)return node;
        return parent[node] = findUPar(parent[node]);
    }
    
    void unionBySize(int u,int v){
        int ulp_u = findUPar(u);
		int ulp_v = findUPar(v);

		if(ulp_u == ulp_v)return;

		if(size[ulp_v] < size[ulp_u]){
			parent[ulp_v] = ulp_u;
			size[ulp_u] += size[ulp_v];
		}else{
			parent[ulp_u] = ulp_v;
			size[ulp_v] += ulp_u;
		}
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        Disjointset ds(n);
        int cntExtraConnections = 0;
        for(auto it: connections){
            int u = it[0];
            int v = it[1];

            if(ds.findUPar(u) == ds.findUPar(v)){
                cntExtraConnections++;
            }else{
                ds.unionBySize(u,v);
            }
        }

        int cmp =0;
        for(int i=0;i < n; i++){
            if(ds.parent[i] == i)cmp++;
        }      
        
        if(cntExtraConnections >= cmp-1)return cmp-1;
        return -1;
    }
};