class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totgas=0, totcost=0;
        int n = gas.size();

        for(int i=0; i<n; i++){
            totgas += gas[i];
            totcost += cost[i];
        }
        if(totcost > totgas) return -1;

        int start=0;
        int curgas = 0;
        for(int i=0; i<n; i++){
            curgas += (gas[i] - cost[i]);

            if(curgas < 0){
                start = i+1;
                curgas = 0;
            }
        }
        return start;
    }
};
