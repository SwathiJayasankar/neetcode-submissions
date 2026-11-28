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
        
        vector<int> dp(n,1);

        int maxi = 1;

        for(int i=0; i<n; i++){
            for(int prev = 0; prev<i; prev++){
                if(nums[prev] < nums[i]){
                    dp[i] = max(dp[i], 1+ dp[prev]);
                    maxi = max(dp[i], maxi);
                }
            }
        }
        return maxi;
    }
};
