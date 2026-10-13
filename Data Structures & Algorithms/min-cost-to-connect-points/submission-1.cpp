class DisjointSet{
    vector<int> par, size;

public:
    DisjointSet(int n){
        par.resize(n+1);
        size.resize(n+1,1);

        for(int i=0; i<=n; i++){
            par[i] = i;
        }
    }

    int findUPar(int node){
        if(par[node] == node){
            return node;
        }
        return par[node] = findUPar(par[node]);
    }

    void unionbySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v) return;

        if(size[ulp_u] < size[ulp_v]){
            par[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }else{
            par[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};



class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        vector<vector<int>> edges;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];

                int edge = abs(x2-x1) + abs(y2-y1);

                edges.push_back({edge,i,j});
            }
        }

        //krushkal
        sort(edges.begin(), edges.end());
        int totcost = 0;

        DisjointSet ds(n);

        for(auto it : edges){
            int cost = it[0];
            int u = it[1];
            int v = it[2];

            if(ds.findUPar(u) != ds.findUPar(v)){
                ds.unionbySize(u,v);
                totcost += cost;
            }
        }
        return totcost;
    }
};
