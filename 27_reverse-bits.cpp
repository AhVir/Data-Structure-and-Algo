class Solution {
public:
    uint32_t reverse(uint32_t n){
        bitset<32> b(n);
        bitset<32> rev;
        for(int i=0; i<32; i++){
            rev[i] = b[31-i];
        }

        return rev.to_ulong();
    }

    int reverseBits(int n) {
        return reverse(n);
    }
};
