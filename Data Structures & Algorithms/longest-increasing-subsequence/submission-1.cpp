class Solution {
public:
    int f(vector<int>& nums, int ind, int prev, vector<vector<int>> dp){
        int n = nums.size();
        if(ind == n) return 0;

        if(dp[ind][prev+1] != -1) return dp[ind][prev+1];

        int notTake = f(nums, ind+1, prev, dp);
        int take = 0;
        if(prev == -1 || nums[ind] > nums[prev]){
            take = 1 + f(nums, ind+1, ind, dp);
        }

        return dp[ind][prev+1] = max(take, notTake);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,0));

        for(int ind=n-1; ind>=0; ind--){
            for(int prev=ind-1; prev>=-1; prev--){

                int nottake = dp[ind+1][prev+1];
                int take = 0;
                if(prev == -1 || nums[ind] > nums[prev]){
                    take = 1 + dp[ind+1][ind+1];
                }
                dp[ind][prev+1] = max(take, nottake);
            }
            
        }

        return dp[0][0];
    }
};
