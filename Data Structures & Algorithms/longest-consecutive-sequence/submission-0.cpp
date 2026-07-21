class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(int x : nums){
            s.insert(x);
        }

        int ans = 0;
        for(auto &it : s){
            if(s.find(it-1) == s.end()){
                int x = it;
                int cnt = 1;
                while(s.find(x+1) != s.end()){
                    cnt++;
                    x = x+1;
                }
                ans = max(ans, cnt);
            }
        }

        return ans;
    }
};
