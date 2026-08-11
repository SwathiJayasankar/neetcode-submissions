class Solution {
public:
    int reverse(int x) {
        int sign = 1;
        if(x < 0){
            x = -x;
            sign = -1;
        }       

        int ans = 0;
        while(x > 0){
            int dig = x % 10;

            if(ans > INT_MAX/10) return 0;

            ans = ans*10 + dig;
            x /= 10;
        }
        return (sign == -1)? -ans : ans;
    }
};
