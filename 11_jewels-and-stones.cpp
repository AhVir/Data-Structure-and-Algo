class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int ins[52];
        for(int i=0; i<52; i++){
            ins[i] = 0;
        }


        for(int i=0; i<stones.length(); i++){
            char temp = stones[i];
            if(temp >= 'A' && temp <= 'Z'){
                ins[temp-'A']++;
            }
            else{
                ins[temp-'a'+26]++;
            }
        }


        int ans = 0;
        for(int i=0; i<jewels.length(); i++){
            char temp = jewels[i];
            if(temp >= 'A' && temp <= 'Z'){
                int val = temp - 'A';
                ans += ins[val];
            }
            else{
                int val = temp - 'a' + 26;
                ans += ins[val];
            }

        }

        return ans;
    }
};
