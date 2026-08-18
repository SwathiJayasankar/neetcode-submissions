class Solution {
public:
    void solve(vector<vector<int>>& ans, vector<int>& nums, vector<int>& ds, vector<bool>& used){
        if(ds.size() == nums.size()){
            ans.push_back(ds);
            return;
        }

        for(int i=0; i<nums.size(); i++){
            if(used[i]) continue;

            ds.push_back(nums[i]);
            used[i] = true;
            solve(ans,nums, ds, used);

            ds.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;

        vector<bool> used(nums.size(), false);

        solve(ans, nums, ds, used);
        return ans;
    }
};
