class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0);

        for(int i=1; i<=n; i++){
            int num = i;
            int noOfOnes = 0;
            while(num > 0){
                noOfOnes += (num & 1);
                num >>= 1;
            }
            ans[i] = noOfOnes;
        }
        return ans;
    }
};
