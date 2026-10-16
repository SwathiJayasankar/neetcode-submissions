class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it : times){
            adj[it[0]].push_back({it[1], it[2]});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > q;
        q.push({0,k});

        vector<int> dist(n+1, 1e9);
        dist[k] = 0;

        while(!q.empty()){
            auto [d, node] = q.top();
            q.pop();

            for(auto it : adj[node]){
                int adjnode = it.first;
                int wt = it.second;

                if(d + wt < dist[adjnode]){
                    dist[adjnode] = d + wt;

                    q.push({d+wt, adjnode});
                }
            }
        }

        int maxDist = 0;
        for(int i=1; i<=n; i++){
            if(dist[i] == 1e9) return -1;
            maxDist = max(maxDist, dist[i]);
        }

        return maxDist;
    }
};
