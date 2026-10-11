class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        vector<vector<int>> adj(26);
        vector<int> indeg(26,0);
        vector<bool> present(26,false);

        for (string &word : words) {
            for (char c : word) {
                present[c - 'a'] = true;
            }
        }

        for(int i=0; i<words.size()-1; i++){
            string s1 = words[i];
            string s2 = words[i+1];

            bool found = false; // edge case {"abc", "ab"}

            for(int j=0; j<min(s1.size(), s2.size()); j++){
                if(s1[j] != s2[j]){
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    indeg[s2[j]-'a']++;
                    found = true;
                    break;
                }
            }

            if(!found && s1.size()>s2.size()){
                return "";
            }
        }

        queue<int> q;
        for(int i=0; i<26; i++){
            if(present[i] && indeg[i]==0){
                q.push(i);
            }
        }

        string ans = "";
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans += char(node + 'a');

            for(auto nei : adj[node]){
                indeg[nei]--;
                if(present[nei] && indeg[nei]==0){
                    q.push(nei);
                }
            }
        }

        // all letters have to be present (no cycle)
        int total = 0;
        for (int i = 0; i < 26; i++) {
            if (present[i]) {
                total++;
            }
        }

        if (ans.size() != total) {
            return "";
        }
        return ans;
    }
};
