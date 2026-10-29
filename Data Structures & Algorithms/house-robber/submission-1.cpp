class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int p2 = nums[0];
        if(n == 1) return p2;

        int p1 = max(nums[0], nums[1]); 
        if(n == 2) return p1;

        for(int i=2; i<n; i++){
            int cur = max(p1, p2+nums[i]);
            p2 = p1;
            p1 = cur;
        }

        return p1;
        

    }
};
