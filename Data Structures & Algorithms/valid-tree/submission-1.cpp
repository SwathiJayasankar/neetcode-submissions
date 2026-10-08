class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> vis(n,0);
        queue<pair<int,int>> q;
        q.push({0,-1});
        vis[0] = 1;

        while(!q.empty()){
            auto [node,par] = q.front();
            q.pop();

            for(auto nbh : adj[node]){
                if(!vis[nbh]){
                    q.push({nbh, node});
                    vis[nbh] = 1;
                }else{
                    if(nbh != par){
                        return false;
                    }
                }
            }
        }

        for(int i=0; i<n; i++){
            if(!vis[i]){
                return false;
            }
        }
        return true;
    }
};
