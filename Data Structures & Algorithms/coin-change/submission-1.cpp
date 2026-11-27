class Solution {
public:
    int coinChange(vector<int>& coins, int amt) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amt+1,0));

        for(int t=0; t<=amt; t++){
            if(t % coins[0] == 0){
                dp[0][t] = t/coins[0];
            }else{
                dp[0][t] = INT_MAX;
            }
        }

        for(int i=1; i<n; i++){
            for(int t=0; t<=amt; t++){
                int nottake = dp[i-1][t];
                int take = INT_MAX;
                if(coins[i] <= t && dp[i][t-coins[i]] != INT_MAX){
                    take = 1 + dp[i][t-coins[i]];
                }

                dp[i][t] = min(take, nottake);
            }
        }

        int ans = dp[n-1][amt];
        if(ans >= INT_MAX) return -1;
        return ans;
    }
};
