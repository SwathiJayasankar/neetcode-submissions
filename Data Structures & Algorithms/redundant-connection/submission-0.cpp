class disjointSet {
    vector<int> par, size;

public:
    disjointSet (int n){
        par.resize(n+1);
        size.resize(n+1, 1);
        
        for(int i=0; i<n; i++){
            par[i] = i;
        }
    }

    int findUPar(int node){
        if(par[node] == node) return node;

        return par[node] = findUPar(par[node]);
    }

    void unionbySize(int u, int v){
        int ulpU = findUPar(u);
        int ulpV = findUPar(v);

        if(ulpU == ulpV) return;

        if(size[ulpU] < size[ulpV]){
            par[ulpU] = ulpV;
            size[ulpV] += size[ulpU];
        }else{
            par[ulpV] = ulpU;
            size[ulpU] += size[ulpV];
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        disjointSet ds(n);

        for(auto it : edges){
            int u = it[0];
            int v = it[1];

            if(ds.findUPar(u) != ds.findUPar(v)){
                ds.unionbySize(u,v);
            }else{
                return it;
            }
        }

    }
};
