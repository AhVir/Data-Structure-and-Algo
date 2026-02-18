class Solution {
public:
    bool hasAlternatingBits(int n) {
        bitset<32> bits(n);
        
        int start = -1;
        for(int i=31; i>=0; i--){
            if(bits[i] == 1){
                start = i;
                break;
            }
        }
        if(start == -1) return true;

        bool nextOne = false;

        if(bits[start] == 0) nextOne = true;

        for(int i=start-1; i>=0; i--){
            if(nextOne == true && bits[i] == 0) return false;
            if(nextOne == false && bits[i] == 1) return false;
            if(nextOne == true && bits[i] == 1){
                nextOne = false;
            }
            if(nextOne == false && bits[i] == 0){
                nextOne = true;
            }
        }


        return true;
    }
};
