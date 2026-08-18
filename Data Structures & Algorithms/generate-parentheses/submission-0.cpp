class Solution {
public:
    void solve(vector<string>& ans, string& ds, int n, int open, int close){
        if(ds.size() == 2*n){
            ans.push_back(ds);
            return;
        }

        if(open < n){
            ds.push_back('(');
            solve(ans, ds, n, open+1, close);
            ds.pop_back();
        }

        if(close < open){
            ds.push_back(')');
            solve(ans,ds, n, open, close+1);
            ds.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string ds;

        solve(ans, ds,n, 0, 0);
        return ans;
    }
};
