class Solution {
public:
    void createComb(vector<int>& nums, vector<vector<int>>& ans, vector<int>& ds, int tar, int i){
        if(tar == 0){
            ans.push_back(ds);
            return;
        }

        if(i == nums.size()) return;

        if(nums[i] <= tar){
            ds.push_back(nums[i]);
            createComb(nums, ans,ds, tar-nums[i], i);

            ds.pop_back();
        }

        createComb(nums, ans, ds, tar, i+1);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> ds;

        createComb(nums, ans, ds, target, 0);
        return ans;
    }
};
