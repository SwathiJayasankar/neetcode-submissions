class Solution {
public:
    bool isPalin(string s, int st, int end){
        while(st <= end){
            if(s[st] != s[end]) return false;
            st++; end--;
        }
        return true;
    }

    void solve(string s, vector<vector<string>>& ans, vector<string>& ds, int ind){
        if(ind == s.size()){
            ans.push_back(ds);
            return;
        }

        for(int i=ind; i<s.size(); i++){
            if(isPalin(s, ind, i)){
                ds.push_back(s.substr(ind, i-ind+1));
                solve(s, ans, ds, i+1);

                ds.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> ds;

        solve(s, ans, ds, 0);
        return ans;
    }
};
