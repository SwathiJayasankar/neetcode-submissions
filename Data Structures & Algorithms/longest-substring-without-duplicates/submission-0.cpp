class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l=0;

        unordered_set<int> st;
        int longest = 0;

        for(int r=0; r<n; r++){
            while(st.find(s[r]) != st.end()){
                st.erase(s[l]);
                l++;
            }
            
            st.insert(s[r]);
            longest = max(longest, r-l+1);
        }

        return longest;
    }
};
