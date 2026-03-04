class Solution {
public:
    bool isPalindrome(int x) {
        string num = to_string(x);
        int n = num.size();

        for(int i=0; i<=n/2; i++){
            if(num[i] != num[n-1-i]) return false; 
        }

        return true;
    }
};
