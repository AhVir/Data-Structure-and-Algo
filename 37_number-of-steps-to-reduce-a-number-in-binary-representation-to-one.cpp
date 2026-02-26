class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        int carry = 0;

        for(int i=s.size()-1; i>0; i--){
            int bit = s[i] - '0';
            bit = bit + carry;

            if(bit == 1){
                // need to do, plus 1 and then, division
                steps += 2;
                carry = 1;  // as 1 + 1 == 10, so last bit 0 and carry = 1
            }
            else if(bit == 0){
                // need to divide by 2, which is
                // nothing but just removing the last bit
                // which we are doing just going to the next bit
                steps++;
                carry = 0;
            }
            else if(bit == 2){
                steps++;
                carry = 1;
            }
        }

        return steps+carry; // since the first bit is always 1
    }
};
