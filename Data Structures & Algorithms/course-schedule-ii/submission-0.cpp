class Solution {
public:
    vector<int> findOrder(int num, vector<vector<int>>& prereq) {
        vector<vector<int>> adj(num);
        vector<int> indeg(num);

        for(auto it : prereq){
            adj[it[1]].push_back(it[0]);
            indeg[it[0]]++;
        }

        vector<int> topo;
        queue<int> q;
        for(int i=0; i<num; i++){
            if(indeg[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(auto nei : adj[node]){
                indeg[nei]--;
                if(indeg[nei]==0){
                    q.push(nei);
                }
            }
        }

        if(topo.size() == num){
            return topo;
        }
        return {};
    }
};
