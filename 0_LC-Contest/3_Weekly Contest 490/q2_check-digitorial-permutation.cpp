class Solution {
public:
    bool isDigitorialPermutation(int n) {
        vector<int> fact(10);
        fact[0] = 1;

        for(int i=1; i<10; i++){
            fact[i] = i * fact[i-1];
        }


        int ans = 0;
        int num = n;
        while(num > 0){
            int digit = num%10;
            num /= 10;

            ans += fact[digit];
        }

        string s = to_string(n);
        sort(s.begin(), s.end());

        // cout << "ans: " <<  ans << endl;

        do {
            // cout << stoi(s) << endl;
            if(s[0] == '0') continue;
            if(stoi(s) == ans) return true;
        } while(next_permutation(s.begin(), s.end()));


        return false;
    }
};