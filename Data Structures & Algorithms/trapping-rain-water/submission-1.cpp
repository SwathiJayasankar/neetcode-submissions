class Solution {
public:
    int trap(vector<int>& ht) {
        int n = ht.size();
        int l = 0, r = n-1;
        int lmax = 0, rmax = 0;

        int ans = 0;

        while(l < r){
            if(ht[l] < ht[r]){      //ans only depends on lesser one - leftmax
                lmax = max(lmax, ht[l]);
                ans += lmax - ht[l];
                l++;
            }else{
                rmax = max(rmax, ht[r]);
                ans += rmax - ht[r];
                r--;
            }
        }

        return ans;
    }
};
