class Solution {
public:
    int rob1(vector<int>& nums, int l, int r) {
        int p0 = 0, p1 = 0;

        for (int i = l; i <= r; i++) {
            int cur = max(p1, p0 + nums[i]);
            p0 = p1;
            p1 = cur;
        }

        return p1;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return nums[0];

        return max(rob1(nums, 0, n-2),
                   rob1(nums, 1, n-1));
    }

};
