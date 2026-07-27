class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> need;
        for(char c : t){
            need[c]++;
        }
        int req = need.size();
        int formed = 0;

        int l=0;
        int minlen = INT_MAX;
        int start =0;

        unordered_map<char,int> window;
        for(int r=0; r<s.size(); r++){
            window[s[r]]++;

            if(need.count(s[r]) && window[s[r]] == need[s[r]]){
                formed++;
            }

            while(formed == req){
                if(r-l+1 < minlen){
                    minlen = r-l+1;
                    start = l;
                }

                window[s[l]]--;
                if(need.count(s[l]) && window[s[l]] < need[s[l]]){
                    formed--;
                }
                l++;
            }
        }

        return (minlen == INT_MAX)? "" : s.substr(start, minlen);
    }
};
