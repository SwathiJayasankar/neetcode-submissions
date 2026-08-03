class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intv) {
        
        sort(intv.begin(), intv.end(), [](vector<int> &a, vector<int> &b){
            return a[1]<b[1];
        });

        int cnt = 0;
        int prevEnd = intv[0][1];

        for(int i=1; i<intv.size(); i++){
            if(intv[i][0] < prevEnd){
                cnt++;
            }else{
                prevEnd = intv[i][1];
            }
        }

        return cnt;
    }
};
