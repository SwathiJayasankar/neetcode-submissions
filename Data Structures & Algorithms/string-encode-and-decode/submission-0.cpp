class Solution {
public:

    string encode(vector<string>& strs) {
        string str = "";
        for(string s : strs){
            int len = s.size();
            str += to_string(len) + '#' + s;
        }
        return str;
    }

    vector<string> decode(string s) {
        vector<string> res;
        
        int i=0;
        while(i<s.size()){
            int j = i+1;
            while(s[j] != '#'){
                j++;
            }

            int len = stoi(s.substr(i,j-i));

            res.push_back(s.substr(j+1, len));

            i = j+1+len;
        }
        return res;
    }
};
