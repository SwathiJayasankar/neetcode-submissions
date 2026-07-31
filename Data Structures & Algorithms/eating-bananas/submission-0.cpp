class Solution {
public:
    int findhrs(vector<int>& piles, int k){
        int tothrs = 0;
        for(int x : piles){
            tothrs += ceil((double)x/k);
        }
        return tothrs;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low= 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = high;

        while(low <= high){
            int mid = low + (high-low)/2;
            int tothrs = findhrs(piles, mid);

            if(tothrs <= h){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};
