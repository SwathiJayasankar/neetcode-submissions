class Solution {
public:
    bool isAlphanum(char c){
        if('z' >= tolower(c) && 'a' <= tolower(c)){
            return true;
        }
        if(c >= '0' && c <= '9') return true;

        return false;
    }

    bool isPalindrome(string s) {
        int i=0, j=s.size()-1;

        while(i<j){            
            while(i<j && !isAlphanum(s[i])){
                i++;
            }
            while(i<j && !isAlphanum(s[j])){
                j--;
            }

            if(tolower(s[i]) != tolower(s[j])){
                return false;
            }else{
                i++; j--;
            }
        }
        return true;
    }
};
