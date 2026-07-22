class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int leastbuy = prices[0];
        int profit = 0;

        for(int i=1; i<prices.size(); i++){
            if(prices[i]>leastbuy){
                profit = max(profit, prices[i]-leastbuy);
            }
            leastbuy = min(leastbuy, prices[i]);
        }

        return profit;
    }
};
