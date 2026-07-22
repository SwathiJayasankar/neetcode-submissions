class Solution {
public:
    int maxArea(vector<int>& hts) {
        int n = hts.size();
        int left=0, right=n-1;
        int ans = INT_MIN;

        while(left < right){
            int len = min(hts[left], hts[right]);
            int width = right - left;

            ans = max(ans, len*width);

            if(hts[left] < hts[right]){
                left++;
            }else{
                right--;
            }
        }

        return ans;
    }
};
