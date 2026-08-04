class Solution {
public:
    int sumofsq(int n){
        int sum=0;
        while(n>0){
            int dig = n%10;
            sum += dig*dig;
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int> s;
        int x = n;

        while(!s.count(x)){
            s.insert(x);

            x = sumofsq(x);

            if(x == 1) return true;           
        }

        return false;
    }
};
