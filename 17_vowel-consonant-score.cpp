class Solution {
public:
    int vowelConsonantScore(string s) {
        int n = s.length();
        int freq[26] = {0};

        int v = 0, con = 0;
        
        for(char c:s){
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') v++;
            else if(c >= 'a' && c <= 'z') con++;
        }


        if(con > 0) return floor(v/con);
        else return 0;
    }
};
