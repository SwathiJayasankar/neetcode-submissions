class Solution {
public:
    bool canFinish(int num, vector<vector<int>>& prereq) {
        vector<vector<int>> adj(num);
        vector<int> indeg(num,0);

        for(auto it : prereq){
            adj[it[1]].push_back(it[0]);
            indeg[it[0]]++;
        }

        queue<int> q;
        for(int i=0; i<num; i++){
            if(indeg[i] == 0){
                q.push(i);
            }
        }
        
        int cnt = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;

            for(auto nei : adj[node]){
                indeg[nei]--;
                if(indeg[nei]==0){
                    q.push(nei);
                }
            }
        }

        return cnt == num;
    }
};
