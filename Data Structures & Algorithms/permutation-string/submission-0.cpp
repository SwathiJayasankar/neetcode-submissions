class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size() < s1.size()) return false;

        vector<int> freq(26,0);
        for(char c : s1){
            freq[c-'a']++;
        }

        vector<int> freq2(26,0);
        for(int i=0; i<s1.size(); i++){
            freq2[s2[i]-'a']++;
        }
        if(freq == freq2) return true;

        if(s2.size() > s1.size()){
            int l=0;
            for(int r=s1.size(); r<s2.size(); r++){
                freq2[s2[r]-'a']++;
                freq2[s2[l]-'a']--;
                l++;
                if(freq == freq2) return true;
            }
        }
        return false;
    }
};
