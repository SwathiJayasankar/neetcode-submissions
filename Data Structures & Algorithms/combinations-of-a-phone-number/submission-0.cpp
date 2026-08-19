class Solution {
public:
    void solve(string digits, vector<string>& ans, string ds, vector<string>& mp, int ind){
        if(ind == digits.size()){
            ans.push_back(ds);
            return;
        }

        int num = digits[ind] - '0';
        string val = mp[num];

        for(int i=0; i<val.size(); i++){
            ds.push_back(val[i]);
            solve(digits, ans, ds, mp, ind+1);

            ds.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0){
            return {};
        }

        vector<string> ans;
        string ds;

        vector<string> mp = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        solve(digits, ans, ds, mp, 0);
        return ans;
    }
};
