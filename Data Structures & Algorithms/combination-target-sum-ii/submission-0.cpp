class Solution {
public:
    void makeComb(vector<int>& candidates, vector<vector<int>>& ans, vector<int>& ds, int tar, int ind){
        if(tar == 0){
            ans.push_back(ds);
            return;
        }
        if(ind == candidates.size()) return;

        for(int i=ind; i<candidates.size(); i++){
            if(i>ind && candidates[i] == candidates[i-1]) continue;

            if(candidates[i] > tar) break;

            ds.push_back(candidates[i]);
            makeComb(candidates, ans, ds, tar-candidates[i], i+1);

            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> ds;

        makeComb(candidates, ans, ds, target, 0);
        return ans;
    }
};
