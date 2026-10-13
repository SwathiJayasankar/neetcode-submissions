class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it : flights){
            adj[it[0]].push_back({it[1], it[2]});
        }

        // steps, node, cost
        queue<vector<int>> q;
        q.push({0,src,0});

        vector<int> dist(n,1e9);
        dist[src] = 0;

        while(!q.empty()){
            int steps = q.front()[0];
            int node = q.front()[1];
            int cost = q.front()[2];
            q.pop();

            if(steps > k) continue;

            for(auto it : adj[node]){
                int adjnode = it.first;
                int wt = it.second;

                if(cost + wt < dist[adjnode] && steps <= k){
                    dist[adjnode] = cost + wt;
                    q.push({steps+1, adjnode, cost+wt});
                }
            }
        }
        if(dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};
