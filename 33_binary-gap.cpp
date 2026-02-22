class Solution {
public:
    int binaryGap(int n) {
        bitset<32> bin(n);

        int start = 0;
        for(int i = 31; i >= 0; i--) {
            if(bin[i] == 1) {
                start = i;
                break;
            }
        }

        cout << bin << endl;
        cout << "start: " << start << endl;

        int ans = 0;

        if(__builtin_popcount(n) < 2) return ans;

        for(int i=start; i>=0; i--){
            if(bin[i] == 1){
                int tempStart = i-1;
                // int tempAns = 0;

                while((tempStart >= 0) && (bin[tempStart] != 1)){
                    tempStart--;
                }

                if(tempStart >= 0)  // only update if a valid 1 exists to the left
                    ans = max(ans, i - tempStart);
                
            }
        }
        cout << "ans: " << ans << endl;

        return ans;
    }
};
