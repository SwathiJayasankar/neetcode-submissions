class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> freq;

        for(int x : nums){
            freq[x]++;

            if(freq[x] > 1){
                return x;
            }
        }
        return 0;
    }
};
