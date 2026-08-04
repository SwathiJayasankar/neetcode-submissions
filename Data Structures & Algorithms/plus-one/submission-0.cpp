class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());

        int carry = 1;
        int i=0;
        while(carry && i<digits.size()){
            int sum = digits[i] + carry;
            digits[i] = sum % 10;
            carry = sum / 10;
            i++;
        }
        if(carry){
            digits.push_back(1);
        }

        reverse(digits.begin(), digits.end());
        return digits;
    }
};
