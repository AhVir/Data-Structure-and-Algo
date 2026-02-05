class Solution {
public:
    bool isSame(vector<int>& s1, vector<int>& s2){
        for(int i=0; i<26; i++){
            if(s1[i] != s2[i]) return false;
        }


        return true;
    }


    bool checkInclusion(string s1, string s2) {
        vector<int> s1_freq(26, 0);
        vector<int> s2_freq(26, 0);

        for(char x:s1){
            int temp = x-'a';
            s1_freq[temp]++;
        }

        int s1_len = s1.length();
        int s2_len = s2.length();

        if(s2_len < s1_len) return false;


        for(int i=0; i<s1_len; i++){
            int temp = s2[i]-'a';
            s2_freq[temp]++;
        }

        if(s1_len == s2_len){
            return isSame(s1_freq, s2_freq);
        }

        if(isSame(s1_freq, s2_freq)) return true;

        for(int i=1; i<=s2_len-s1_len; i++){
            // removing the last char
            int prev = s2[i-1]-'a';
            s2_freq[prev]--;

            // adding the next one
            int next = s2[i-1+s1_len]-'a';
            s2_freq[next]++;

            if(isSame(s1_freq, s2_freq)) return true;
        }


        return false;
    }
};
