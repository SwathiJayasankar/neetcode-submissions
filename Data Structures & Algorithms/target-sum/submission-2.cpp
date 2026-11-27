class Solution {
public:
    int rec(vector<int>& nums, int tar,int ind, int sum, vector<vector<int>>& dp, int offset){
        if(ind < 0){
            return sum == tar;
        }

        if(dp[ind][sum+ offset] != -1) return dp[ind][sum+ offset];

        int add = rec(nums, tar, ind-1, sum+ nums[ind], dp, offset);
        int sub = rec(nums, tar, ind-1, sum- nums[ind], dp, offset);

        return dp[ind][sum+offset] = add + sub;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(),0);
        
        vector<vector<int>> dp(n, vector<int>(2*total+1, -1));

        return rec(nums, target, n-1, 0, dp, total);
    }
};
