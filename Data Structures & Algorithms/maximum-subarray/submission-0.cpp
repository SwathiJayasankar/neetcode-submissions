class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxsum = INT_MIN;

        for(int x : nums){
            sum += x;
            maxsum = max(maxsum, sum);
            if(sum < 0){
                sum = 0;
            }
            
        }
        return maxsum;
    }
};
